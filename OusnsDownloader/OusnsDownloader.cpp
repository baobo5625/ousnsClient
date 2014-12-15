/*

Copyright (c) 2003, Arvid Norberg
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/
#include "OusnsDownloader.h"
#define TORRENT_USE_WPATH 1


std::string to_string(int v, int width)
{
	std::stringstream s;
	s.flags(std::ios_base::right);
	s.width(width);
	s.fill(' ');
	s << v;
	return s.str();
}

std::string& to_string(float v, int width, int precision = 3)
{
	// this is a silly optimization
	// to avoid copying of strings
	enum { num_strings = 20 };
	static std::string buf[num_strings];
	static int round_robin = 0;
	std::string& ret = buf[round_robin];
	++round_robin;
	if (round_robin >= num_strings) round_robin = 0;
	ret.resize(20);
	int size = snprintf(&ret[0], 20, "%*.*f", width, precision, v);
	ret.resize((std::min)(size, width));
	return ret;
}

std::string add_suffix(float val, char const* suffix = 0)
{
	std::string ret;
	if (val == 0)
	{
		ret.resize(4 + 2, ' ');
		if (suffix) ret.resize(4 + 2 + strlen(suffix), ' ');
		return ret;
	}

	const char* prefix[] = {"kB", "MB", "GB", "TB"};
	const int num_prefix = sizeof(prefix) / sizeof(const char*);
	for (int i = 0; i < num_prefix; ++i)
	{
		val /= 1000.f;
		if (std::fabs(val) < 1000.f)
		{
			ret = to_string(val, 4);
			ret += prefix[i];
			if (suffix) ret += suffix;
			return ret;
		}
	}
	ret = to_string(val, 4);
	ret += "PB";
	if (suffix) ret += suffix;
	return ret;
}

std::string const& piece_bar(libtorrent::bitfield const& p, int width)
{
#ifdef ANSI_TERMINAL_COLORS
	static const char* lookup[] =
	{
		// black, blue, cyan, white
		"40", "44", "46", "47"
	};

	const int table_size = sizeof(lookup) / sizeof(lookup[0]);
#else
	static const char char_lookup[] =
	{ ' ', '.', ':', '-', '+', '*', '#'};

	const int table_size = sizeof(char_lookup) / sizeof(char_lookup[0]);
#endif
	
	double piece_per_char = p.size() / double(width);
	static std::string bar;
	bar.clear();
	bar.reserve(width * 6);
	bar += "[";
	if (p.size() == 0)
	{
		for (int i = 0; i < width; ++i) bar += ' ';
		bar += "]";
		return bar;
	}

	// the [piece, piece + pieces_per_char) range is the pieces that are represented by each character
	double piece = 0;
	for (int i = 0; i < width; ++i, piece += piece_per_char)
	{
		int num_pieces = 0;
		int num_have = 0;
		int end = (std::max)(int(piece + piece_per_char), int(piece) + 1);
		for (int k = int(piece); k < end; ++k, ++num_pieces)
			if (p[k]) ++num_have;
		int color = int(std::ceil(num_have / float(num_pieces) * (table_size - 1)));
#ifdef ANSI_TERMINAL_COLORS
		bar += esc(lookup[color]);
		bar += " ";
#else
		bar += char_lookup[color];
#endif
	}
#ifdef ANSI_TERMINAL_COLORS
	bar += esc("0");
#endif
	bar += "]";
	return bar;
}

std::string const& progress_bar(int progress, int width, char const* code = "33")
{
	static std::string bar;
	bar.clear();
	bar.reserve(width + 10);

	int progress_chars = (progress * width + 500) / 1000;
	bar = esc(code);
	std::fill_n(std::back_inserter(bar), progress_chars, '#');
	std::fill_n(std::back_inserter(bar), width - progress_chars, '-');
	bar += esc("0");
	return bar;
}

int peer_index(libtorrent::tcp::endpoint addr, std::vector<libtorrent::peer_info> const& peers)
{
	using namespace libtorrent;
	std::vector<peer_info>::const_iterator i = std::find_if(peers.begin()
		, peers.end(), boost::bind(&peer_info::ip, _1) == addr);
	if (i == peers.end()) return -1;

	return i - peers.begin();
}

void print_peer_info(std::string& out, std::vector<libtorrent::peer_info> const& peers)
{
	using namespace libtorrent;
	if (print_ip) out += "IP                           ";
#ifndef TORRENT_DISABLE_GEO_IP
	if (print_as) out += "AS                                         ";
#endif
	out += "down     (total | peak   )  up      (total | peak   ) sent-req recv flags         source  ";
	if (print_fails) out += "fail hshf ";
	if (print_send_bufs) out += "rq sndb            quota rcvb            q-bytes ";
	if (print_timers) out += "inactive wait timeout q-time ";
	out += "disk   rtt ";
	if (print_block) out += "block-progress ";
#ifndef TORRENT_DISABLE_RESOLVE_COUNTRIES
	out += "country ";
#endif
	if (print_peer_rate) out += "peer-rate ";
	out += "client \n";

	char str[500];
	for (std::vector<peer_info>::const_iterator i = peers.begin();
		i != peers.end(); ++i)
	{
		if (i->flags & (peer_info::handshake | peer_info::connecting | peer_info::queued))
			continue;

		if (print_ip)
		{
			error_code ec;
			snprintf(str, sizeof(str), "%-22s:%-5d ", i->ip.address().to_string(ec).c_str(), i->ip.port());
			out += str;
		}

#ifndef TORRENT_DISABLE_GEO_IP
		if (print_as)
		{
			error_code ec;
			snprintf(str, sizeof(str), "%-42s ", i->inet_as_name.c_str());
			out += str;
		}
#endif

		snprintf(str, sizeof(str)
			, "%s%s (%s|%s) %s%s (%s|%s) %s%3d (%3d) %3d %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c "
			, esc("32"), add_suffix(i->down_speed, "/s").c_str()
			, add_suffix(i->total_download).c_str(), add_suffix(i->download_rate_peak, "/s").c_str()
			, esc("31"), add_suffix(i->up_speed, "/s").c_str(), add_suffix(i->total_upload).c_str()
			, add_suffix(i->upload_rate_peak, "/s").c_str(), esc("0")

			, i->download_queue_length
			, i->target_dl_queue_length
			, i->upload_queue_length

			, (i->flags & peer_info::interesting)?'I':'.'
			, (i->flags & peer_info::choked)?'C':'.'
			, (i->flags & peer_info::remote_interested)?'i':'.'
			, (i->flags & peer_info::remote_choked)?'c':'.'
			, (i->flags & peer_info::supports_extensions)?'e':'.'
			, (i->flags & peer_info::local_connection)?'l':'r'
			, (i->flags & peer_info::seed)?'s':'.'
			, (i->flags & peer_info::on_parole)?'p':'.'
			, (i->flags & peer_info::optimistic_unchoke)?'O':'.'
			, (i->read_state == peer_info::bw_limit)?'r':
				(i->read_state == peer_info::bw_network)?'R':'.'
			, (i->write_state == peer_info::bw_limit)?'w':
				(i->write_state == peer_info::bw_network)?'W':'.'
			, (i->flags & peer_info::snubbed)?'S':'.'
			, (i->flags & peer_info::upload_only)?'U':'D'
			, (i->flags & peer_info::endgame_mode)?'-':'.'
#ifndef TORRENT_DISABLE_ENCRYPTION
			, (i->flags & peer_info::rc4_encrypted)?'E':
				(i->flags & peer_info::plaintext_encrypted)?'e':'.'
#else
			, '.'
#endif
			, (i->source & peer_info::tracker)?'T':'_'
			, (i->source & peer_info::pex)?'P':'_'
			, (i->source & peer_info::dht)?'D':'_'
			, (i->source & peer_info::lsd)?'L':'_'
			, (i->source & peer_info::resume_data)?'R':'_'
			, (i->source & peer_info::incoming)?'I':'_');
		out += str;

		if (print_fails)
		{
			snprintf(str, sizeof(str), "%3d %3d "
				, i->failcount, i->num_hashfails);
			out += str;
		}
		if (print_send_bufs)
		{
			snprintf(str, sizeof(str), "%2d %6d (%s) %5d %6d (%s) %6d "
				, i->requests_in_buffer, i->used_send_buffer, add_suffix(i->send_buffer_size).c_str()
				, i->send_quota, i->used_receive_buffer, add_suffix(i->receive_buffer_size).c_str()
				, i->queue_bytes);
			out += str;
		}
		if (print_timers)
		{
			snprintf(str, sizeof(str), "%8d %4d %7d %6d "
				, total_seconds(i->last_active)
				, total_seconds(i->last_request)
				, i->request_timeout
				, total_seconds(i->download_queue_time));
			out += str;
		}
		snprintf(str, sizeof(str), "%s %4d "
			, add_suffix(i->pending_disk_bytes).c_str()
			, i->rtt);
		out += str;

		if (print_block)
		{
			if (i->downloading_piece_index >= 0)
			{
				out += progress_bar(
					i->downloading_progress * 1000 / i->downloading_total, 14);
			}
			else
			{
				out += progress_bar(0, 14);
			}
		}

#ifndef TORRENT_DISABLE_RESOLVE_COUNTRIES
		if (i->country[0] == 0)
		{
			out += " ..";
		}
		else
		{
			snprintf(str, sizeof(str), " %c%c", i->country[0], i->country[1]);
			out += str;
		}
#endif
		if (print_peer_rate)
		{
			snprintf(str, sizeof(str), " %s", add_suffix(i->remote_dl_rate, "/s").c_str());
			out += str;
		}
		out += " ";

		if (i->flags & peer_info::handshake)
		{
			out += esc("31");
			out += " waiting for handshake";
			out += esc("0");
			out += "\n";
		}
		else if (i->flags & peer_info::connecting)
		{
			out += esc("31");
			out += " connecting to peer";
			out += esc("0");
			out += "\n";
		}
		else if (i->flags & peer_info::queued)
		{
			out += esc("33");
			out += " queued";
			out += esc("0");
			out += "\n";
		}
		else
		{
			out += " ";
			out += i->client;
			out += "\n";
		}
	}
}




// monitored_dir is true if this torrent is added because
// it was found in the directory that is monitored. If it
// is, it should be remembered so that it can be removed
// if it's no longer in that directory.
void add_torrent(libtorrent::session& ses
	, handles_t& handles
	, std::string const& torrent
	, float preferred_ratio
	, int allocation_mode
	, path const& save_path
	, bool monitored_dir
	, int torrent_upload_limit
	, int torrent_download_limit)
{
	using namespace libtorrent;

	boost::intrusive_ptr<torrent_info> t;
	error_code ec;
	std::wstring temp(torrent.length(),L' ');
	std::copy(torrent.begin(), torrent.end(), temp.begin());
	t = new torrent_info(temp.c_str(), ec);
 	//t = new torrent_info(torrent.c_str(), ec);
	if (ec)
	{
		fprintf(stderr, "%s: %s\n", torrent.c_str(), ec.message().c_str());
		return;
	}

	printf("%s\n", t->name().c_str());

	add_torrent_params p;
	lazy_entry resume_data;

	std::string filename = (save_path / (t->name() + ".resume")).string();

	std::vector<char> buf;
	//error_code ec = new error_code();
	if (load_file(filename.c_str(), buf,ec) == 0)
		p.resume_data = &buf;

	p.ti = t;
	p.save_path = save_path;
	p.storage_mode = (storage_mode_t)allocation_mode;
	p.paused = true;
	p.duplicate_is_error = false;
	p.auto_managed = true;
	torrent_handle h = ses.add_torrent(p, ec);
	if (ec)
	{
		fprintf(stderr, "failed to add torrent: %s\n", ec.message().c_str());
		return;
	}

	handles.insert(std::pair<const std::string, torrent_handle>(
		monitored_dir?std::string(torrent):std::string(), h));

	h.set_max_connections(max_connections_per_torrent);
	h.set_max_uploads(-1);
	h.set_ratio(preferred_ratio);
	h.set_upload_limit(torrent_upload_limit);
	h.set_download_limit(torrent_download_limit);
#ifndef TORRENT_DISABLE_RESOLVE_COUNTRIES
	h.resolve_countries(true);
#endif
}

void scan_dir(path const& dir_path
	, libtorrent::session& ses
	, handles_t& handles
	, float preferred_ratio
	, int allocation_mode
	, path const& save_path
	, int torrent_upload_limit
	, int torrent_download_limit)
{
	std::set<std::string> valid;

	using namespace libtorrent;

	for (directory_iterator i(dir_path), end; i != end; ++i)
	{
		if (extension(*i) != ".torrent") continue;
		std::string file = i->path().string();

		handles_t::iterator k = handles.find(file);
		if (k != handles.end())
		{
			valid.insert(file);
			continue;
		}

		// the file has been added to the dir, start
		// downloading it.
		add_torrent(ses, handles, file, preferred_ratio, allocation_mode
			, save_path, true, torrent_upload_limit, torrent_download_limit);
		valid.insert(file);
	}

	// remove the torrents that are no longer in the directory

	for (handles_t::iterator i = handles.begin(); !handles.empty() && i != handles.end();)
	{
		if (i->first.empty() || valid.find(i->first) != valid.end())
		{
			++i;
			continue;
		}

		torrent_handle& h = i->second;
		if (!h.is_valid())
		{
			handles.erase(i++);
			continue;
		}
		
		h.auto_managed(false);
		h.pause();
		// the alert handler for save_resume_data_alert
		// will save it to disk
		h.save_resume_data();

		handles.erase(i++);
	}
}

/*
 * this function will find the active_torrent list and return the active_torrent index pointed one
 */
libtorrent::torrent_handle get_active_torrent(handles_t const& handles)
{
	if (active_torrent >= handles.size()
		|| active_torrent < 0) return libtorrent::torrent_handle();
	handles_t::const_iterator i = handles.begin();
	std::advance(i, active_torrent);
	return i->second;
}

void print_alert(libtorrent::alert const* a, std::string& str)
{
	using namespace libtorrent;

#ifdef ANSI_TERMINAL_COLORS
	if (a->category() & alert::error_notification)
	{
		str += esc("31");
	}
	else if (a->category() & (alert::peer_notification | alert::storage_notification))
	{
		str += esc("33");
	}
#endif
	str += "[";
	str += time_now_string();
	str += "] ";
	str += a->message();
#ifdef ANSI_TERMINAL_COLORS
	str += esc("0");
#endif

	if (g_log_file)
		fprintf(g_log_file, "[%s] %s\n", time_now_string(),  a->message().c_str());
}

int save_file(boost::filesystem::path const& filename, std::vector<char>& v)
{
	using namespace libtorrent;

	file f;
	error_code ec;
	if (!f.open(filename, file::write_only, ec)) return -1;
	if (ec) return -1;
	file::iovec_t b = {&v[0], v.size()};
	size_type written = f.writev(0, &b, 1, ec);
	if (written != v.size()) return -3;
	if (ec) return -3;
	return 0;
}

void handle_alert(libtorrent::session& ses, libtorrent::alert* a
	, handles_t const& handles)
{
	using namespace libtorrent;

	if (torrent_finished_alert* p = alert_cast<torrent_finished_alert>(a))
	{
		p->handle.set_max_connections(max_connections_per_torrent / 2);

		// write resume data for the finished torrent
		// the alert handler for save_resume_data_alert
		// will save it to disk
		torrent_handle h = p->handle;
		h.save_resume_data();
	}
	else if (save_resume_data_alert* p = alert_cast<save_resume_data_alert>(a))
	{
		torrent_handle h = p->handle;
		TORRENT_ASSERT(p->resume_data);
		if (p->resume_data)
		{
			std::vector<char> out;
			bencode(std::back_inserter(out), *p->resume_data);
			save_file(h.save_path() / (h.name() + ".resume"), out);
			if (std::find_if(handles.begin(), handles.end()
				, boost::bind(&handles_t::value_type::second, _1) == h) == handles.end())
				ses.remove_torrent(h);
		}
	}
	else if (save_resume_data_failed_alert* p = alert_cast<save_resume_data_failed_alert>(a))
	{
		torrent_handle h = p->handle;
		if (std::find_if(handles.begin(), handles.end()
			, boost::bind(&handles_t::value_type::second, _1) == h) == handles.end())
			ses.remove_torrent(h);
	}
}

static char const* state_str[] =
	{"checking (q)", "checking", "dl metadata"
	, "downloading", "finished", "seeding", "allocating", "checking (r)"};

int main(int argc, char* argv[])
{
#if BOOST_VERSION < 103400
	using boost::filesystem::no_check;
	path::default_name_check(no_check);
#endif
	setlocale(LC_ALL,"");
	/*
	if (argc == 1)
	{
		fprintf(stderr, "usage: client_test [OPTIONS] [TORRENT|MAGNETURL]\n\n"
			"OPTIONS:\n"
			"  -f <log file>         logs all events to the given file\n"
			"  -o <limit>            limits the number of simultaneous\n"
			"                        half-open TCP connections to the\n"
			"                        given number.\n"
			"  -p <port>             sets the listen port\n"
			"  -r <ratio>            sets the preferred share ratio\n"
			"  -d <rate>             limits the download rate\n"
			"  -u <rate>             limits the upload rate\n"
			"  -S <limit>            limits the upload slots\n"
			"  -a <mode>             sets the allocation mode. [compact|full]\n"
			"  -s <path>             sets the save path for downloads\n"
			"  -U <rate>             sets per-torrent upload rate\n"
			"  -D <rate>             sets per-torrent download rate\n"
			"  -m <path>             sets the .torrent monitor directory\n"
			"  -b <IP>               sets IP of the interface to bind the\n"
			"                        listen socket to\n"
			"  -w <seconds>          sets the retry time for failed web seeds\n"
			"  -t <seconds>          sets the scan interval of the monitor dir\n"
			"  -x <file>             loads an emule IP-filter file\n"
			"  -c <limit>            sets the max number of connections\n"
			"  -T <limit>            sets the max number of connections per torrent\n"
			"  -C <limit>            sets the max cache size. Specified in 16kB blocks\n"
			"  -F <seconds>          sets the UI refresh rate. This is the number of\n"
			"                        seconds between screen refreshes.\n"
			"  -n                    announce to trackers in all tiers\n"
			"  -h                    allow multiple connections from the same IP\n"
			"  -A <num pieces>       allowed pieces set size\n"
			"  -R <num blocks>       number of blocks per read cache line\n"
			"  -O                    Disallow disk job reordering\n"
			"  -P <host:port>        Use the specified SOCKS5 proxy\n"
			"  -L <user:passwd>      Use the specified username and password for the\n"
			"                        proxy specified by -P\n"
			"  -W <num peers>        Set the max number of peers to keep in the peer list\n"
			"  "
			"\n\n"
			"TORRENT is a path to a .torrent file\n"
			"MAGNETURL is a magnet: url\n")
			;
		return 0;
	}
	*/
	using namespace libtorrent;
	
	settings = get_upload_setting();
	using namespace boost::interprocess;




	//Create a lock in another  shared memory 
	windows_shared_memory sharedMutexLock
		(create_only               //only create
		,"ousns shared memory lock"          //name
		,read_write   //read-write mode
		,sizeof(boost::interprocess::interprocess_mutex));

	 windows_shared_memory sharedMutex
		(create_only               //only create
		,"ousns shared memory"          //name
		,read_write   //read-write mode
		,sizeof(shared_memory_log));
	//sharedMutex.truncate(sizeof(shared_memory_log));


	mapped_region region
		(sharedMutex                       //What to map
		,read_write   //Map it as read-write
		);

	mapped_region regionLock
		(sharedMutexLock                       //What to map
		,read_write   //Map it as read-write
		);

	void * addr       = region.get_address();
	void * addr2 = regionLock.get_address();

	//Construct the shared structure in memory
	//boost::interprocess::interprocess_mutex* mutex = new(addr)boost::interprocess::interprocess_mutex;
	//shared_memory_log * data = new ((void *)((int)addr + sizeof(boost::interprocess::interprocess_mutex))) shared_memory_log;
	boost::interprocess::interprocess_mutex* mutex = new(addr2)boost::interprocess::interprocess_mutex();
	//mutex->interprocess_mutex();
	shared_memory_log * data = new (addr) shared_memory_log;

	
	char *mem = static_cast<char*>(region.get_address());

	shared_memory_log *localMem = (shared_memory_log*) malloc(sizeof(shared_memory_log));;
	localMem = new(localMem) shared_memory_log;
/*
	settings.user_agent = "client_test/" LIBTORRENT_VERSION;
	settings.auto_upload_slots_rate_based = true;
	//settings.announce_to_all_trackers = true;
	settings.optimize_hashing_for_speed = false;
	settings.disk_cache_algorithm = session_settings::largest_contiguous;
*/
	
	int refresh_delay = 1;

	std::deque<std::string> events;

	ptime next_dir_scan = time_now();
	
	std::vector<char> in;
	error_code ec;
	if (load_file(".ses_state", in,ec) == 0)
	{
		lazy_entry e;
		if (lazy_bdecode(&in[0], &in[0] + in.size(), e) == 0)
			ses.load_state(e);
	}

#ifndef TORRENT_DISABLE_DHT
	settings.use_dht_as_fallback = false;

	ses.add_dht_router(std::make_pair(
			std::string("router.bittorrent.com"), 6881));
	ses.add_dht_router(std::make_pair(
			std::string("router.utorrent.com"), 6881));
	ses.add_dht_router(std::make_pair(
			std::string("router.bitcomet.com"), 6881));

	ses.start_dht();
#endif

#ifndef TORRENT_DISABLE_GEO_IP
	ses.load_asnum_db("GeoIPASNum.dat");
	ses.load_country_db("GeoIP.dat");
#endif

	// load the torrents given on the commandline

	

	for (int i = 1; i < argc; ++i)
	{
		if (argv[i][0] != '-')
		{
			// interpret this as a torrent

			// match it against the <hash>@<tracker> format
			if (strlen(argv[i]) > 45
				&& is_hex(argv[i], 40)
				&& string_begins_no_case(argv[i] + 40, "@http"))
			{
				sha1_hash info_hash;
				from_hex(argv[i], 40, (char*)&info_hash[0]);

				add_torrent_params p;
				p.tracker_url = argv[i] + 41;
				p.info_hash = info_hash;
				p.save_path = save_path;
				p.storage_mode = (storage_mode_t)allocation_mode;
				p.paused = true;
				p.duplicate_is_error = false;
				p.auto_managed = true;
				magnet_links.push_back(p);
				continue;
			}

			torrents.push_back(argv[i]);
			continue;
		}

		// if there's a flag but no argument following, ignore it
		if (argc == i) continue;
		char const* arg = argv[i+1];
		switch (argv[i][1])
		{
			case 'f': g_log_file = fopen(arg, "w+"); break;
			case 'o': ses.set_max_half_open_connections(atoi(arg)); break;
			case 'h': settings.allow_multiple_connections_per_ip = true; --i; break;
			case 'p': listen_port = atoi(arg); break;
			case 'r':
				preferred_ratio = atoi(arg);
				if (preferred_ratio != 0 && preferred_ratio < 1.f) preferred_ratio = 1.f;
				break;
			case 'n': settings.announce_to_all_tiers = true; --i; break;
			case 'd': ses.set_download_rate_limit(atoi(arg) * 1000); break;
			case 'u': ses.set_upload_rate_limit(atoi(arg) * 1000); break;
			case 'S': ses.set_max_uploads(atoi(arg)); break;
			case 'a':
				if (strcmp(arg, "allocate") == 0) allocation_mode = storage_mode_allocate;
				if (strcmp(arg, "compact") == 0) allocation_mode = storage_mode_compact;
				break;
			case 's': save_path = arg; break;
			case 'U': torrent_upload_limit = atoi(arg) * 1000; break;
			case 'D': torrent_download_limit = atoi(arg) * 1000; break;
			case 'm': monitor_dir = arg; break;
			case 'b': bind_to_interface = arg; break;
			case 'w': settings.urlseed_wait_retry = atoi(arg); break;
			case 't': poll_interval = atoi(arg); break;
			case 'F': refresh_delay = atoi(arg); break;
			case 'x':
				{
					FILE* filter = fopen(arg, "r");
					if (filter)
					{
						ip_filter fil;
						unsigned int a,b,c,d,e,f,g,h, flags;
						while (fscanf(filter, "%u.%u.%u.%u - %u.%u.%u.%u %u\n", &a, &b, &c, &d, &e, &f, &g, &h, &flags) == 9)
						{
							address_v4 start((a << 24) + (b << 16) + (c << 8) + d);
							address_v4 last((e << 24) + (f << 16) + (g << 8) + h);
							if (flags <= 127) flags = ip_filter::blocked;
							else flags = 0;
							fil.add_rule(start, last, flags);
						}
						ses.set_ip_filter(fil);
						fclose(filter);
					}
				}
				break;
			case 'c': ses.set_max_connections(atoi(arg)); break;
			case 'T': max_connections_per_torrent = atoi(arg); break;
			case 'C':
				settings.cache_size = atoi(arg);
				settings.use_read_cache = settings.cache_size > 0;
				settings.cache_buffer_chunk_size = settings.cache_size / 100;
				break;
			case 'A': settings.allowed_fast_set_size = atoi(arg); break;
			case 'R': settings.read_cache_line_size = atoi(arg); break;
			case 'O': settings.allow_reordered_disk_operations = false; --i; break;
			case 'W': settings.max_peerlist_size = atoi(arg); break;
			case 'P':
				{
					char* port = (char*) strchr(arg, ':');
					if (port == 0)
					{
						fprintf(stderr, "invalid proxy hostname, no port found\n");
						break;
					}
					*port++ = 0;
					ps.hostname = arg;
					ps.port = atoi(port);
					if (ps.port == 0) {
						fprintf(stderr, "invalid proxy port\n");
						break;
					}
					if (ps.type == proxy_settings::none)
						ps.type = proxy_settings::socks5;
				}
				break;
			case 'L':
				{
					char* pw = (char*) strchr(arg, ':');
					if (pw == 0)
					{
						fprintf(stderr, "invalid proxy username and password specified\n");
						break;
					}
					*pw++ = 0;
					ps.username = arg;
					ps.password = pw;
					ps.type = proxy_settings::socks5_pw;
				}
				break;
		}
		++i; // skip the argument
	}
	



	ses.set_peer_proxy(ps);
	ses.set_web_seed_proxy(ps);
	ses.set_tracker_proxy(ps);
#ifndef TORRENT_DISABLE_DHT
	ses.set_dht_proxy(ps);
#endif

	ses.listen_on(std::make_pair(listen_port, listen_port + 10)
		, bind_to_interface.c_str());

	ses.set_settings(settings);


	
	/*
	for (std::vector<add_torrent_params>::iterator i = magnet_links.begin()
		, end(magnet_links.end()); i != end; ++i)
	{
		error_code ec;
		torrent_handle h = ses.add_torrent(*i, ec);
		if (ec)
		{
			fprintf(stderr, "failed to add torrent: %s\n", ec.message().c_str());
			continue;
		}

		handles.insert(std::pair<const std::string, torrent_handle>(std::string(), h));

		h.set_max_connections(max_connections_per_torrent);
		h.set_max_uploads(-1);
		h.set_ratio(preferred_ratio);
		h.set_upload_limit(torrent_upload_limit);
		h.set_download_limit(torrent_download_limit);
	}
	*/
	for (std::vector<std::string>::iterator i = torrents.begin()
		, end(torrents.end()); i != end; ++i)
	{
		// first see if this is a torrentless download
		if (std::strstr(i->c_str(), "magnet:") == i->c_str())
		{
			add_torrent_params p;
			p.save_path = save_path;
			p.storage_mode = (storage_mode_t)allocation_mode;
			printf("adding MANGET link: %s\n", i->c_str());
			error_code ec;
			torrent_handle h = add_magnet_uri(ses, i->c_str(), p, ec);
			if (ec)
			{
				fprintf(stderr, "%s\n", ec.message().c_str());
				continue;
			}

			handles.insert(std::pair<const std::string, torrent_handle>(std::string(), h));

			h.set_max_connections(max_connections_per_torrent);
			h.set_max_uploads(-1);
			h.set_ratio(preferred_ratio);
			h.set_upload_limit(torrent_upload_limit);
			h.set_download_limit(torrent_download_limit);
			continue;
		}

		// if it's a torrent file, open it as usual
		else
			add_torrent(ses, handles, i->c_str(), preferred_ratio
			, allocation_mode, save_path, false
			, torrent_upload_limit, torrent_download_limit);
	}
	
	
	// main loop


	for (;;)
	{
		//Set the current job to 0
		localMem->currentJob = 0;
		char c = 0;
		while (sleep_and_input(&c, refresh_delay))
		{


			if (c == 27)
			{
				// escape code, read another character
#ifdef _WIN32
				c = _getch();
#else
				c = getc(stdin);
#endif
				if (c != '[') break;
#ifdef _WIN32
				c = _getch();
#else
				c = getc(stdin);
#endif
				if (c == 65)
				{
					// arrow up
					--active_torrent;
					if (active_torrent < 0) active_torrent = 0;
				}
				else if (c == 66)
				{
					// arrow down
					++active_torrent;
					if (active_torrent >= handles.size()) active_torrent = handles.size() - 1;
				}
			}
			// the space is used to paused the current whole session
			if (c == ' ')
			{
				if (ses.is_paused()) ses.resume();
				else ses.pause();
			}

			if (c == 'm')
			{
				printf("saving peers for torrents\n");

				std::vector<peer_list_entry> peers;
				for (handles_t::iterator i = handles.begin();
					i != handles.end(); ++i)
				{
					i->second.get_full_peer_list(peers);
					FILE* f = fopen(("peers_" + i->second.name()).c_str(), "w+");
					if (!f) break;
					for (std::vector<peer_list_entry>::iterator k = peers.begin()
						, end(peers.end()); k != end; ++k)
					{
						fprintf(f, "%s\t%d\n", print_address(k->ip.address()).c_str()
#ifndef TORRENT_DISABLE_GEO_IP
							, ses.as_for_ip(k->ip.address())
#else
							, 0
#endif
							);
					}
				}
			}

			if (c == 'q') break;

			/*
			 * Used to check if the file is complete
			 */
			if (c == 'j')
			{
			
				torrent_handle h = get_active_torrent(handles);
				if (h.is_valid()) h.force_recheck();
			}

			if (c == 'r')
			{
				torrent_handle h = get_active_torrent(handles);
				if (h.is_valid()) h.force_reannounce();
			}

			if (c == 's')
			{
				torrent_handle h = get_active_torrent(handles);
				if (h.is_valid()) h.set_sequential_download(!h.is_sequential_download());
			}

			if (c == 'o')
			{
				torrent_handle h = get_active_torrent(handles);
				if (h.is_valid())
				{
					int num_pieces = h.get_torrent_info().num_pieces();
					if (num_pieces > 300) num_pieces = 300;
					for (int i = 0; i < num_pieces; ++i)
					{
						h.set_piece_deadline(i, (i+5) * 1000, torrent_handle::alert_when_available);
					}
				}
			}

			if (c == 'v')
			{
				torrent_handle h = get_active_torrent(handles);
				if (h.is_valid()) h.scrape_tracker();
			}

			if (c == 'p')
			{
				torrent_handle h = get_active_torrent(handles);
				if (h.is_valid())
				{
					if (!h.is_auto_managed() && h.is_paused())
					{
						h.auto_managed(true);
					}
					else
					{
						h.auto_managed(false);
						h.pause();
					}
					// the alert handler for save_resume_data_alert
					// will save it to disk
					h.save_resume_data();
				}
			}

			if (c == 'c')
			{
				torrent_handle h = get_active_torrent(handles);
				if (h.is_valid()) h.clear_error();
			}

			// toggle displays
			if (c == 't') print_trackers = !print_trackers;
			if (c == 'i') print_peers = !print_peers;
			if (c == 'l') print_log = !print_log;
			if (c == 'd') print_downloads = !print_downloads;
			if (c == 'f') print_file_progress = !print_file_progress;
			if (c == 'h') show_pad_files = !show_pad_files;
			if (c == 'a') print_piece_bar = !print_piece_bar;
			if (c == 'g') show_dht_status = !show_dht_status;
			// toggle columns
			if (c == '1') print_ip = !print_ip;
			if (c == '2') print_as = !print_as;
			if (c == '3') print_timers = !print_timers;
			if (c == '4') print_block = !print_block;
			if (c == '5') print_peer_rate = !print_peer_rate;
			if (c == '6') print_fails = !print_fails;
			if (c == '7') print_send_bufs = !print_send_bufs;
		}
		if (c == 'q') break;

		
		mutex->lock();
		memcpy(localMem->commandEntry,data->commandEntry,sizeof(CommandEntry) * data->currentCommand);
		localMem->currentCommand = data->currentCommand;
		//Reset the current command pointer
		data->currentCommand = 0;
		mutex->unlock();
		CommandEntry commandEntry;
		while(localMem->currentCommand > 0){
			localMem->currentCommand = localMem->currentCommand - 1;
			commandEntry = localMem->commandEntry[localMem->currentCommand];
			int torrent_index = 0;
			switch(commandEntry.commandChar){
				case 'a':
					if(commandEntry.commandMagnetURI[0]){
						//The magnet URI is set
						add_torrent_params p;
						p.save_path = save_path;
						p.storage_mode = (storage_mode_t)allocation_mode;
						//printf("adding MANGET link: %s\n", i->c_str());
						error_code ec;
						torrent_handle h = add_magnet_uri(ses, std::string(commandEntry.commandMagnetURI), p, ec);
						if (ec)
						{
							fprintf(stderr, "%s\n", ec.message().c_str());
							continue;
						}

						handles.insert(std::pair<const std::string, torrent_handle>(std::string(), h));

						h.set_max_connections(max_connections_per_torrent);
						h.set_max_uploads(-1);
						h.set_ratio(preferred_ratio);
						h.set_upload_limit(torrent_upload_limit);
						h.set_download_limit(torrent_download_limit);
					}
						
					else
						add_torrent(ses, handles, std::string(commandEntry.commandParam[1]), preferred_ratio
						, allocation_mode, save_path, false
						, torrent_upload_limit, torrent_download_limit);
					break;
				case 's':

					
					for (handles_t::iterator i = handles.begin();
						i != handles.end(); ++torrent_index)
					{
						torrent_handle& h = i->second;

						std::string name = h.name();
						if(name.compare(std::string(commandEntry.commandTarget)) == 0){

							handles.erase(i++);
						}
					}
					break;
				default:
					break;
			}
			//localMem->currentCommand--;
		}
		int terminal_width = 80;

#ifndef _WIN32
		{
			winsize size;
			ioctl(STDOUT_FILENO, TIOCGWINSZ, (char*)&size);
			terminal_width = size.ws_col;

			if (terminal_width < 64)
				terminal_width = 64;
		}
#endif

		// loop through the alert queue to see if anything has happened.
		std::auto_ptr<alert> a;
		a = ses.pop_alert();
		std::string now = time_now_string();
		while (a.get())
		{
			std::string event_string;

			::print_alert(a.get(), event_string);
			::handle_alert(ses, a.get(), handles);

			events.push_back(event_string);
			if (events.size() >= 20) events.pop_front();

			a = ses.pop_alert();
		}

		session_status sess_stat = ses.status();

		std::string out;
		out = "[q] quit [i] toggle peers [d] toggle downloading pieces [p] toggle paused "
			"[a] toggle piece bar [s] toggle download sequential [f] toggle files "
			"[j] force recheck [space] toggle session pause [c] clear error [v] scrape [g] show DHT\n"
			"[1] toggle IP [2] toggle AS [3] toggle timers [4] toggle block progress "
			"[5] toggle peer rate [6] toggle failures [7] toggle send buffers\n";

		char str[500];
		int torrent_index = 0;
		torrent_handle active_handle;
		for (handles_t::iterator i = handles.begin();
			i != handles.end(); ++torrent_index)
		{
			torrent_handle& h = i->second;
			//make sure to use this before access any other handle
			if (!h.is_valid())
			{
				//invalid handle
				handles.erase(i++);
				continue;
			}
			else
			{
				++i;
			}

#ifdef ANSI_TERMINAL_COLORS
			char const* term = "\x1b[0m";
#else
			char const* term = "";
#endif
			if (active_torrent == torrent_index)
			{
				term = "\x1b[0m\x1b[7m";
				out += esc("7");
				out += "*";
			}
			else
			{
				out += " ";
			}

			int queue_pos = h.queue_position();
			if (queue_pos == -1) out += "-  ";
			else
			{
				snprintf(str, sizeof(str), "%-3d", queue_pos);
				out += str;
			}

			if (h.is_paused()) out += esc("34");
			else out += esc("37");

			std::string name = h.name();
			//std::wstring name = h.name();
			std::wstring name_w(name.length(),L'');
			std::copy(name.begin(),name.end(),name_w.begin());
			if (name.size() > MAX_PATH) name.resize(MAX_PATH);
			//Initial the entry
			new(&localMem->jobEntry[localMem->currentJob]) JobEntry;
			// Put the file name into the local memory
			//If the job does not have a name	
			if (name.compare("")== 0)
				name="Retriving File Info";
			strcpy(localMem->jobEntry[localMem->currentJob].jobName,name.c_str());
			std::string tempStr = h.save_path().string();
			if(tempStr.size() > MAX_PATH)
				tempStr.resize(MAX_PATH);
			strcpy(localMem->jobEntry[localMem->currentJob].jobPath,tempStr.c_str());

			if (name.size() > 40) name.resize(40);

			snprintf(str, sizeof(str), "%-40s %s ", name.c_str(), term);
			out += str;

			torrent_status s = h.status();

			// Set the torrent status to the local memory
			localMem->jobEntry[localMem->currentJob].jobStatus = s.state;
			
			bool paused = h.is_paused();
			if (paused)
				localMem->jobEntry[localMem->currentJob].jobPaused = 1;
			bool auto_managed = h.is_auto_managed();
			bool sequential_download = h.is_sequential_download();

			if (!s.error.empty())
			{
				out += esc("31");
				out += "error ";
				out += s.error;
				out += esc("0");
				out += "\n";
				continue;
			}
			//h.torrent_handle(); 

			int seeds = 0;
			int downloaders = 0;

			if (s.num_complete >= 0) seeds = s.num_complete;
			else seeds = s.list_seeds;

			if (s.num_incomplete >= 0) downloaders = s.num_incomplete;
			else downloaders = s.list_peers - s.list_seeds;

			if (s.state != torrent_status::queued_for_checking && s.state != torrent_status::checking_files)
			{
				snprintf(str, sizeof(str), "%-13s down: (%s%s%s) up: %s%s%s (%s%s%s) swarm: %4d:%4d"
					"  bw queue: (%d|%d) all-time (Rx: %s%s%s Tx: %s%s%s) seed rank: %x%s\n"
					, (paused && !auto_managed)?"paused":(paused && auto_managed)?"queued":state_str[s.state]
					, esc("32"), add_suffix(s.total_download).c_str(), term
					, esc("31"), add_suffix(s.upload_rate, "/s").c_str(), term
					, esc("31"), add_suffix(s.total_upload).c_str(), term
					, downloaders, seeds
					, s.up_bandwidth_queue, s.down_bandwidth_queue
					, esc("32"), add_suffix(s.all_time_download).c_str(), term
					, esc("31"), add_suffix(s.all_time_upload).c_str(), term
					, s.seed_rank, esc("0"));
				out += str;

				if (torrent_index != active_torrent && s.state == torrent_status::seeding) continue;
				char const* progress_bar_color = "33"; // yellow
				if (s.state == torrent_status::downloading_metadata)
				{
					progress_bar_color = "35"; // magenta
				}
				else if (s.current_tracker.empty())
				{
					progress_bar_color = "31"; // red
				}
				else if (sess_stat.has_incoming_connections)
				{
					progress_bar_color = "32"; // green
				}

				snprintf(str, sizeof(str), "     %-10s: %s%-11"PRId64"%s Bytes %6.2f%% %s\n"
					, sequential_download?"sequential":"progress"
					, esc("32"), s.total_done, esc("0")
					, s.progress_ppm / 10000.f
					, progress_bar(s.progress_ppm / 1000, terminal_width - 43, progress_bar_color).c_str());
				out += str;
				// Copy the total Done to the local memory, using KB as unit
				localMem->jobEntry[localMem->currentJob].totalDone = s.total_done/1024;

				localMem->jobEntry[localMem->currentJob].totalProgress_ppm = s.progress_ppm;
			}
			else
			{
				snprintf(str, sizeof(str), "%-13s %s\n"
					, state_str[s.state]
					, progress_bar(s.progress_ppm / 1000, terminal_width - 43 - 20, "35").c_str());
				out += str;
			}

			if (print_piece_bar && s.progress_ppm < 1000000 && s.progress > 0)
			{
				out += "     ";
				out += piece_bar(s.pieces, terminal_width - 7);
				out += "\n";
			}

			if (s.state != torrent_status::queued_for_checking && s.state != torrent_status::checking_files)
			{
				boost::posix_time::time_duration t = s.next_announce;
				snprintf(str, sizeof(str)
					, "     peers: %s%d%s (%s%d%s) seeds: %s%d%s distributed copies: %s%4.2f%s "
					"sparse regions: %d download: %s%s%s next announce: %s%02d:%02d:%02d%s "
					"tracker: %s%s%s\n"
					, esc("37"), s.num_peers, esc("0")
					, esc("37"), s.connect_candidates, esc("0")
					, esc("37"), s.num_seeds, esc("0")
					, esc("37"), s.distributed_copies, esc("0")
					, s.sparse_regions
					, esc("32"), add_suffix(s.download_rate, "/s").c_str(), esc("0")
					, esc("37"), t.hours(), t.minutes(), t.seconds(), esc("0")
					, esc("36"), s.current_tracker.c_str(), esc("0"));
				out += str;

				//Set the peers and seeds here
				localMem->jobEntry[localMem->currentJob].peers = s.num_peers;
				localMem->jobEntry[localMem->currentJob].seeds = s.num_seeds;
				localMem->jobEntry[localMem->currentJob].distributed_full_copies = s.distributed_full_copies;
				localMem->jobEntry[localMem->currentJob].distributed_fraction = s.distributed_fraction;
				// Set the download rate
				localMem->jobEntry[localMem->currentJob].totalDownloadRate = s.download_rate;
				

			}

			/*if (print_file_progress
				&& s.state != torrent_status::seeding
				&& h.has_metadata())
				*/
			//if (s.state != torrent_status::seeding

				//&& h.has_metadata())
			if(h.has_metadata())
			{
				
				std::vector<size_type> file_progress;
				//h.file_progress(file_progress);
				h.file_progress(file_progress,libtorrent::torrent_handle::piece_granularity);
				torrent_info const& info = h.get_torrent_info();
				
				for (int i = 0; i < info.num_files(); ++i)
				{
					bool pad_file = info.file_at(i).pad_file;
					if (!show_pad_files && pad_file) continue;
					int progress = info.file_at(i).size > 0
						?file_progress[i] * 1000 / info.file_at(i).size:1000;

					char const* color = (file_progress[i] == info.file_at(i).size)
						?"32":"33";

					snprintf(str, sizeof(str), "%s %s %-5.2f%% %s %s%s\n",
						progress_bar(progress, 100, color).c_str()
						, pad_file?esc("34"):""
						, progress / 10.f
						, add_suffix(file_progress[i]).c_str()
						, info.file_at(i).path.leaf().c_str()
						, pad_file?esc("0"):"");
					out += str;

					strcpy(localMem->jobEntry[localMem->currentJob].\
						files[localMem->jobEntry[localMem->currentJob].currentFile].fileName,\
						info.file_at(i).path.leaf().c_str());
					localMem->jobEntry[localMem->currentJob].\
						files[localMem->jobEntry[localMem->currentJob].currentFile].fileSize = info.file_at(i).size/1024;
					localMem->jobEntry[localMem->currentJob].\
						files[localMem->jobEntry[localMem->currentJob].currentFile].fileProgress = progress;
					tempStr = info.file_at(i).path.string();
					if(tempStr.size() > MAX_PATH)
						tempStr.resize(MAX_PATH);
					strcpy(localMem->jobEntry[localMem->currentJob].\
						files[localMem->jobEntry[localMem->currentJob].currentFile].filePath,tempStr.c_str());
					//Increase the file counter
					localMem->jobEntry[localMem->currentJob].currentFile++;
				}

				localMem->jobEntry[localMem->currentJob].jobSize = info.total_size()/1024;
				
			}
			//Set the state of the current Job
			localMem->jobEntry[localMem->currentJob].jobStatus  = (int)s.state;
			localMem->currentJob++;
			
			
			if (torrent_index != active_torrent) continue;
			active_handle = h;
			
		}

		cache_status cs = ses.get_cache_status();
		if (cs.blocks_read < 1) cs.blocks_read = 1;
		if (cs.blocks_written < 1) cs.blocks_written = 1;

		snprintf(str, sizeof(str), "==== conns: %d down: %s%s%s (%s%s%s) up: %s%s%s (%s%s%s) "
			"tcp/ip: %s%s%s %s%s%s DHT: %s%s%s %s%s%s tracker: %s%s%s %s%s%s ====\n"
			, sess_stat.num_peers
			, esc("32"), add_suffix(sess_stat.download_rate, "/s").c_str(), esc("0")
			, esc("32"), add_suffix(sess_stat.total_download).c_str(), esc("0")
			, esc("31"), add_suffix(sess_stat.upload_rate, "/s").c_str(), esc("0")
			, esc("31"), add_suffix(sess_stat.total_upload).c_str(), esc("0")
			, esc("32"), add_suffix(sess_stat.ip_overhead_download_rate, "/s").c_str(), esc("0")
			, esc("31"), add_suffix(sess_stat.ip_overhead_upload_rate, "/s").c_str(), esc("0")
			, esc("32"), add_suffix(sess_stat.dht_download_rate, "/s").c_str(), esc("0")
			, esc("31"), add_suffix(sess_stat.dht_upload_rate, "/s").c_str(), esc("0")
			, esc("32"), add_suffix(sess_stat.tracker_download_rate, "/s").c_str(), esc("0")
			, esc("31"), add_suffix(sess_stat.tracker_upload_rate, "/s").c_str(), esc("0"));
		out += str;



		snprintf(str, sizeof(str), "==== waste: %s fail: %s unchoked: %d / %d "
			"bw queues: %8d (%d) | %8d (%d) cache: w: %"PRId64"%% r: %"PRId64"%% size: %s (%s) / %s dq: %"PRId64" ===\n"
			, add_suffix(sess_stat.total_redundant_bytes).c_str()
			, add_suffix(sess_stat.total_failed_bytes).c_str()
			, sess_stat.num_unchoked, sess_stat.allowed_upload_slots
			, sess_stat.up_bandwidth_bytes_queue
			, sess_stat.up_bandwidth_queue
			, sess_stat.down_bandwidth_bytes_queue
			, sess_stat.down_bandwidth_queue
			, (cs.blocks_written - cs.writes) * 100 / cs.blocks_written
			, cs.blocks_read_hit * 100 / cs.blocks_read
			, add_suffix(cs.cache_size * 16 * 1024).c_str()
			, add_suffix(cs.read_cache_size * 16 * 1024).c_str()
			, add_suffix(cs.total_used_buffers * 16 * 1024).c_str()
			, cs.queued_bytes);
		out += str;

		snprintf(str, sizeof(str), "==== optimistic unchoke: %d unchoke counter: %d ====\n"
			, sess_stat.optimistic_unchoke_counter, sess_stat.unchoke_counter);
		out += str;

#ifndef TORRENT_DISABLE_DHT
		if (show_dht_status)
		{
			snprintf(str, sizeof(str), "DHT nodes: %d DHT cached nodes: %d total DHT size: %"PRId64"\n"
				, sess_stat.dht_nodes, sess_stat.dht_node_cache, sess_stat.dht_global_nodes);
			out += str;

			for (std::vector<dht_lookup>::iterator i = sess_stat.active_requests.begin()
				, end(sess_stat.active_requests.end()); i != end; ++i)
			{
				snprintf(str, sizeof(str), "  %s %d (%d) ( timeouts %d responses %d)\n"
					, i->type, i->outstanding_requests, i->branch_factor, i->timeouts, i->responses);
				out += str;
			}
		}
#endif

		if (active_handle.is_valid())
		{
			torrent_handle h = active_handle;
			torrent_status s = h.status();

			if ((print_downloads && s.state != torrent_status::seeding)
				|| print_peers)
				h.get_peer_info(peers);

			out += "====== ";
			out += h.name();
			out += " ======\n";

			if (print_peers && !peers.empty())
				print_peer_info(out, peers);

			if (print_trackers)
			{
				std::vector<announce_entry> tr = h.trackers();
				ptime now = time_now();
				for (std::vector<announce_entry>::iterator i = tr.begin()
					, end(tr.end()); i != end; ++i)
				{
					snprintf(str, sizeof(str), "%2d %-55s fails: %-3d (%-3d) %s %s\n"
						, i->tier, i->url.c_str(), i->fails, i->fail_limit, i->verified?"OK ":"-  "
						, i->updating?"updating"
							:!i->will_announce(now)?""
							:to_string(total_seconds(i->next_announce - now), 8).c_str());
					out += str;
				}
			}

			if (print_downloads)
			{

				h.get_download_queue(queue);
				std::sort(queue.begin(), queue.end(), boost::bind(&partial_piece_info::piece_index, _1)
					< boost::bind(&partial_piece_info::piece_index, _2));

				std::vector<cached_piece_info> pieces;
				ses.get_cache_info(h.info_hash(), pieces);

				for (std::vector<partial_piece_info>::iterator i = queue.begin();
					i != queue.end(); ++i)
				{
					cached_piece_info* cp = 0;
					std::vector<cached_piece_info>::iterator cpi = std::find_if(pieces.begin(), pieces.end()
						, boost::bind(&cached_piece_info::piece, _1) == i->piece_index);
					if (cpi != pieces.end()) cp = &*cpi;

					snprintf(str, sizeof(str), "%5d: [", i->piece_index);
					out += str;
					for (int j = 0; j < i->blocks_in_piece; ++j)
					{
						int index = peer_index(i->blocks[j].peer(), peers) % 36;
						char chr = '+';
						if (index >= 0)
							chr = (index < 10)?'0' + index:'A' + index - 10;

						char const* color = "";

#ifdef ANSI_TERMINAL_COLORS
						if (cp && cp->blocks[j]) color = esc("36;7");
						else if (i->blocks[j].bytes_progress > 0
							&& i->blocks[j].state == block_info::requested)
						{
							if (i->blocks[j].num_peers > 1) color = esc("1;7");
							else color = esc("33;7");
							chr = '0' + (i->blocks[j].bytes_progress / float(i->blocks[j].block_size) * 10);
						}
						else if (i->blocks[j].state == block_info::finished) color = esc("32;7");
						else if (i->blocks[j].state == block_info::writing) color = esc("35;7");
						else if (i->blocks[j].state == block_info::requested) color = esc("0");
						else { color = esc("0"); chr = ' '; }
#else
						if (cp && cp->blocks[j]) chr = 'c';
						else if (i->blocks[j].state == block_info::finished) chr = '#';
						else if (i->blocks[j].state == block_info::writing) chr = '+';
						else if (i->blocks[j].state == block_info::requested) chr = '-';
						else chr = ' ';
#endif
						snprintf(str, sizeof(str), "%s%c", color, chr);
						out += str;
					}
#ifdef ANSI_TERMINAL_COLORS
					out += esc("0");
#endif
					char const* piece_state[4] = {"", " slow", " medium", " fast"};
					snprintf(str, sizeof(str), "]%s", piece_state[i->piece_state]);
					out += str;
					if (cp)
					{
						snprintf(str, sizeof(str), " %scache age: %-.1f"
							, i->piece_state > 0?"| ":""
							, total_milliseconds(time_now() - cp->last_use) / 1000.f);
						out += str;
					}
					out += "\n";
				}

				for (std::vector<cached_piece_info>::iterator i = pieces.begin()
					, end(pieces.end()); i != end; ++i)
				{
					if (i->kind != cached_piece_info::read_cache) continue;
					snprintf(str, sizeof(str), "%5d: [", i->piece);
					out += str;
					for (std::vector<bool>::iterator k = i->blocks.begin()
						, end(i->blocks.end()); k != end; ++k)
					{
						char const* color = "";
						char chr = ' ';
#ifdef ANSI_TERMINAL_COLORS
						color = *k?esc("33;7"):esc("0");
#else
						chr = *k?'#':' ';
#endif
						snprintf(str, sizeof(str), "%s%c", color, chr);
						out += str;
					}
#ifdef ANSI_TERMINAL_COLORS
					out += esc("0");
#endif
					snprintf(str, sizeof(str), "] cache age: %-.1f\n"
						, total_milliseconds(time_now() - i->last_use) / 1000.f);
					out += str;
				}
				out += "___________________________________\n";
			}

			/*
			if (print_file_progress
				&& s.state != torrent_status::seeding
				&& h.has_metadata())
			{
				std::vector<size_type> file_progress;
				h.file_progress(file_progress);
				torrent_info const& info = h.get_torrent_info();
				for (int i = 0; i < info.num_files(); ++i)
				{
					bool pad_file = info.file_at(i).pad_file;
					if (!show_pad_files && pad_file) continue;
					int progress = info.file_at(i).size > 0
						?file_progress[i] * 1000 / info.file_at(i).size:1000;

					char const* color = (file_progress[i] == info.file_at(i).size)
						?"32":"33";

					snprintf(str, sizeof(str), "%s %s %-5.2f%% %s %s%s\n",
						progress_bar(progress, 100, color).c_str()
						, pad_file?esc("34"):""
						, progress / 10.f
						, add_suffix(file_progress[i]).c_str()
						, info.file_at(i).path.leaf().c_str()
						, pad_file?esc("0"):"");
					out += str;
				}

				out += "___________________________________\n";
			}
			*/

		}

		if (print_log)
		{
			for (std::deque<std::string>::iterator i = events.begin();
				i != events.end(); ++i)
			{
				out += "\n";
				out += *i;
			}
		}
		
		clear_home();
		puts(out.c_str());


		//data->mutex.lock();
		if(localMem->currentJob)
			puts("has job!!!!!");
		mutex->lock();
		//Enter the lock region


		
		//Copy the out put to the share memory
		memcpy(data->jobEntry,localMem->jobEntry, sizeof(JobEntry )* localMem->currentJob);
		data->currentJob = localMem->currentJob;

		mutex->unlock();
		if (!monitor_dir.empty()
			&& next_dir_scan < time_now())
		{
			scan_dir(monitor_dir, ses, handles, preferred_ratio
				, allocation_mode, save_path, torrent_upload_limit
				, torrent_download_limit);
			next_dir_scan = time_now() + seconds(poll_interval);
		}

	}

	// keep track of the number of resume data
	// alerts to wait for
	int num_resume_data = 0;
	ses.pause();
	for (handles_t::iterator i = handles.begin();
		i != handles.end(); ++i)
	{
		torrent_handle& h = i->second;
		if (!h.is_valid()) continue;
		if (h.is_paused()) continue;
		if (!h.has_metadata()) continue;

		printf("saving resume data for %s\n", h.name().c_str());
		// save_resume_data will generate an alert when it's done
		h.save_resume_data();
		++num_resume_data;
	}
	printf("waiting for resume data\n");

	while (num_resume_data > 0)
	{
		alert const* a = ses.wait_for_alert(seconds(30));
		if (a == 0)
		{
			printf(" aborting with %d outstanding "
				"torrents to save resume data for\n", num_resume_data);
			break;
		}

		std::auto_ptr<alert> holder = ses.pop_alert();

		std::string log;
		::print_alert(holder.get(), log);
		printf("%s\n", log.c_str());

		if (alert_cast<save_resume_data_failed_alert>(a))
		{
			--num_resume_data;
			continue;
		}

		save_resume_data_alert const* rd = alert_cast<save_resume_data_alert>(a);
		if (!rd) continue;
		--num_resume_data;

		if (!rd->resume_data) continue;

		torrent_handle h = rd->handle;
		std::vector<char> out;
		bencode(std::back_inserter(out), *rd->resume_data);
		save_file((h.save_path() / h.name()).string() + ".resume", out);
	}
	printf("saving session state\n");
	{
		entry session_state;
		ses.save_state(session_state);

		std::vector<char> out;
		bencode(std::back_inserter(out), session_state);
		save_file(".ses_state", out);
	}

	printf("closing session");

	//Start to destroy the lock as well as free the shared memory
	free(localMem);
	

	return 0;
}


/*
 *  This function will return a setting that will be used for 
 *  hidden upload.
 */
session_settings get_upload_setting(void){
	//session_settings settings;
	using namespace libtorrent;
	libtorrent::session_settings settings = min_memory_usage();

	settings.user_agent =  CLIENT_NAME OUSNS_VERSION;

	settings.auto_upload_slots_rate_based = true;
	//settings.announce_to_all_trackers = true;
	settings.optimize_hashing_for_speed = false;
	settings.disk_cache_algorithm = session_settings::largest_contiguous;
	settings.ignore_limits_on_local_network = true;
	settings.lazy_bitfields =  true;
	settings.use_dht_as_fallback = false;

	settings.prioritize_partial_pieces = false;
	settings.auto_manage_startup = false;
	settings.strict_super_seeding = true;
	settings.low_prio_disk = true;
	settings.strict_end_game_mode = true;
	settings.allow_multiple_connections_per_ip = false;
	return settings;
}

/*
 *  This function will return a setting that will be used for 
 *  hidden upload.
 */
session_settings get_normal_download_setting(void){
	//session_settings settings;
	using namespace libtorrent;
	libtorrent::session_settings settings = min_memory_usage();

	settings.user_agent =  CLIENT_NAME OUSNS_VERSION;

	settings.auto_upload_slots_rate_based = true;
	//settings.announce_to_all_trackers = true;
	settings.optimize_hashing_for_speed = false;
	settings.disk_cache_algorithm = session_settings::largest_contiguous;
	settings.ignore_limits_on_local_network = true;
	settings.lazy_bitfields =  true;
	settings.use_dht_as_fallback = false;

	settings.prioritize_partial_pieces = false;
	settings.auto_manage_startup = false;
	settings.strict_super_seeding = true;
	settings.low_prio_disk = true;
	settings.strict_end_game_mode = true;
	settings.allow_multiple_connections_per_ip = false;
	return settings;
}


void add_magnet_links_from_client(char *link){
	using namespace libtorrent;
	if (strlen(link) > 45
		&& is_hex(link, 40)
		&& string_begins_no_case(link + 40, "@http"))
		{
		sha1_hash info_hash;
		from_hex(link, 40, (char*)&info_hash[0]);
		add_torrent_params p;
		p.tracker_url = link + 41;
		p.info_hash = info_hash;
		p.save_path = save_path;
		p.storage_mode = (storage_mode_t)allocation_mode;
		p.paused = true;
		p.duplicate_is_error = false;
		p.auto_managed = true;
		
		error_code ec;
		torrent_handle h = ses.add_torrent(p, ec);
		if (ec)
		{
			fprintf(stderr, "failed to add torrent: %s\n", ec.message().c_str());
		}

		handles.insert(std::pair<const std::string, torrent_handle>(std::string(), h));

		h.set_max_connections(max_connections_per_torrent);
		h.set_max_uploads(-1);
		h.set_ratio(preferred_ratio);
		h.set_upload_limit(torrent_upload_limit);
		h.set_download_limit(torrent_download_limit);
		//magnet_links.push_back(p);
	}

}

void add_torrent_files_from_client(char *file_name){
	using namespace libtorrent;

	torrents.push_back(file_name);

	for (std::vector<std::string>::iterator i = torrents.begin()
		, end(torrents.end()); i != end; ++i)
	{
		// first see if this is a torrentless download
		if (std::strstr(i->c_str(), "magnet:") == i->c_str())
		{
			add_torrent_params p;
			p.save_path = save_path;
			p.storage_mode = (storage_mode_t)allocation_mode;
			printf("adding MANGET link: %s\n", i->c_str());
			error_code ec;
			torrent_handle h = add_magnet_uri(ses, i->c_str(), p, ec);
			if (ec)
			{
				fprintf(stderr, "%s\n", ec.message().c_str());
				continue;
			}

			handles.insert(std::pair<const std::string, torrent_handle>(std::string(), h));

			h.set_max_connections(max_connections_per_torrent);
			h.set_max_uploads(-1);
			h.set_ratio(preferred_ratio);
			h.set_upload_limit(torrent_upload_limit);
			h.set_download_limit(torrent_download_limit);
			continue;
		}

		// if it's a torrent file, open it as usual
		add_torrent(ses, handles, i->c_str(), preferred_ratio
			, allocation_mode, save_path, false
			, torrent_upload_limit, torrent_download_limit);
	}

}