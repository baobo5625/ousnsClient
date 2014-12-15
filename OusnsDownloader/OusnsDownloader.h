
#include <iterator>
#include "libtorrent/config.hpp"

#ifdef _MSC_VER
#pragma warning(push, 1)
#endif

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/bind.hpp>
#include <boost/interprocess/windows_shared_memory.hpp>
//#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/detail/config_begin.hpp>
//[doc_anonymous_mutex_shared_data
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/detail/config_end.hpp>

#include "doc_anonymous_mutex_shared_data.hpp"
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include "libtorrent/extensions/metadata_transfer.hpp"
#include "libtorrent/extensions/ut_metadata.hpp"
#include "libtorrent/extensions/ut_pex.hpp"
#include "libtorrent/extensions/smart_ban.hpp"

#include "libtorrent/entry.hpp"
#include "libtorrent/bencode.hpp"
#include "libtorrent/session.hpp"
#include "libtorrent/identify_client.hpp"
#include "libtorrent/alert_types.hpp"
#include "libtorrent/ip_filter.hpp"
#include "libtorrent/magnet_uri.hpp"
#include "libtorrent/bitfield.hpp"
#include "libtorrent/file.hpp"

#include "lang.h"
#include "version.h"

using boost::bind;


#ifdef _WIN32

#if defined(_MSC_VER)
#	define for if (false) {} else for
#endif

#include <windows.h>
#include <conio.h>
#include <ostream>


bool sleep_and_input(char* c, int sleep)
{
	for (int i = 0; i < sleep * 2; ++i)
	{
		if (_kbhit())
		{
			*c = _getch();
			return true;
		}
		Sleep(500);
	}
	return false;
};

void clear_home()
{
	CONSOLE_SCREEN_BUFFER_INFO si;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &si);
	COORD c = {0, 0};
	DWORD n;
	FillConsoleOutputCharacter(h, ' ', si.dwSize.X * si.dwSize.Y, c, &n);
	SetConsoleCursorPosition(h, c);
}

#else

#include <stdlib.h>
#include <stdio.h>

#include <termios.h>
#include <string.h>
#include <sys/ioctl.h>

#define ANSI_TERMINAL_COLORS

struct set_keypress
{
	set_keypress()
	{
		termios new_settings;
		tcgetattr(0,&stored_settings);
		new_settings = stored_settings;
		// Disable canonical mode, and set buffer size to 1 byte
		new_settings.c_lflag &= (~ICANON);
		new_settings.c_cc[VTIME] = 0;
		new_settings.c_cc[VMIN] = 1;
		tcsetattr(0,TCSANOW,&new_settings);
	}
	~set_keypress() { tcsetattr(0,TCSANOW,&stored_settings); }
	termios stored_settings;
};

bool sleep_and_input(char* c, int sleep)
{
	// sets the terminal to single-character mode
	// and resets when destructed
	set_keypress s;

	fd_set set;
	FD_ZERO(&set);
	FD_SET(0, &set);
	timeval tv = {sleep, 0};
	if (select(1, &set, 0, 0, &tv) > 0)
	{
		*c = getc(stdin);
		return true;
	}
	return false;
}

void clear_home()
{
	puts("\033[2J\033[0;0H");
}

#endif

bool print_trackers = false;
bool print_peers = false;
bool print_log = false;
bool print_downloads = false;
bool print_piece_bar = false;
bool print_file_progress = false;
bool show_pad_files = false;
bool show_dht_status = false;
bool sequential_download = false;

bool print_ip = true;
bool print_as = false;
bool print_timers = false;
bool print_block = false;
bool print_peer_rate = false;
bool print_fails = false;
bool print_send_bufs = true;

FILE* g_log_file = 0;
/*
 * The actived torrent index 
 */
int active_torrent = 0;

char const* esc(char const* code)
{
#ifdef ANSI_TERMINAL_COLORS
	// this is a silly optimization
	// to avoid copying of strings
	enum { num_strings = 200 };
	static char buf[num_strings][20];
	static int round_robin = 0;
	char* ret = buf[round_robin];
	++round_robin;
	if (round_robin >= num_strings) round_robin = 0;
	ret[0] = '\033';
	ret[1] = '[';
	int i = 2;
	int j = 0;
	while (code[j]) ret[i++] = code[j++];
	ret[i++] = 'm';
	ret[i++] = 0;
	return ret;
#else
	return "";
#endif
}

typedef std::multimap<std::string, libtorrent::torrent_handle> handles_t;

int listen_port = 6881;
float preferred_ratio = 0.f;
int allocation_mode = libtorrent::storage_mode_sparse;
//std::string save_path(".");
std::string save_path("C:\\OusnsDownload1");
//std::string save_path("C:\\Ousnsœ¬‘ÿ\\œ¬‘ÿ2");
std::string resume_save_path = std::string(getenv("APPDATA")) + "\\TorrentCache";
int torrent_upload_limit = 0;
int torrent_download_limit = 0;
std::string monitor_dir;
std::string bind_to_interface = "";
int poll_interval = 5;
int max_connections_per_torrent = 50;

using boost::bind;
using boost::filesystem::path;
using boost::filesystem::exists;
using boost::filesystem::directory_iterator;
using boost::filesystem::extension;
using namespace libtorrent;

/*
 * The proxy settings
 */
proxy_settings ps;

	// the string is the filename of the .torrent file, but only if
	// it was added through the directory monitor. It is used to
	// be able to remove torrents that were added via the directory
	// monitor when they're not in the directory anymore.
	handles_t handles;


/*
 * Initiate the session with the fingerprint and without start listening
 */
session ses(fingerprint(FINGERPRINT_ID, OUSNS_VERSION_MAJOR, OUSNS_VERSION_MINOR, 0, 0)
		, session::start_default_features | session::add_default_plugins
		, alert::all_categories
			& ~(alert::dht_notification
			+ alert::progress_notification
			+ alert::debug_notification
			+ alert::stats_notification));

/*
 * Current setting for the session
 */
session_settings settings;


/*
 * The magnet links vector
 */
std::vector<add_torrent_params> magnet_links;

/* 
 * the torrent file vector
 */
std::vector<std::string> torrents;

/*
 * The following variables used in main loop
 */
std::vector<peer_info> peers;
std::vector<partial_piece_info> queue;

//HANDLE m_hRead = GetStdHandle(STD_INPUT_HANDLE);
//HANDLE m_hWrite = GetStdHandle(STD_OUTPUT_HANDLE);

/*
 *  This function will return a setting that will be used for 
 *  hidden upload.
 */
session_settings get_upload_setting(void);


/*
 * The function will add a magnet link to the magnet_links vector variable
 */
void add_magnet_links_from_client(char *link);

/*
 * This function will add the torrent file name to the torrent vector variable
 */ 

void add_torrent_files_from_client(char *file_name);

/*
 * This function will set the setting to the normal download mode
 */
session_settings get_normal_download_setting(void);

std::vector<int> get_download_rate(torrent_handle handler);
