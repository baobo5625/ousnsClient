#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OuSns {

	/// <summary>
	/// RecommendFocusTab 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class RecommendFocusTab : public System::Windows::Forms::Form
	{
	public:
		RecommendFocusTab(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~RecommendFocusTab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevComponents::DotNetBar::SuperTabControl^  superTabControl7;
	protected: 
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel21;
	private: DevComponents::AdvTree::AdvTree^  advTree2;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader17;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader18;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader19;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader20;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader21;
	private: DevComponents::AdvTree::Node^  node12;
	private: DevComponents::AdvTree::Node^  node14;
	private: DevComponents::AdvTree::Cell^  cell9;
	private: DevComponents::AdvTree::Cell^  cell10;
	private: DevComponents::AdvTree::Cell^  cell12;
	private: DevComponents::AdvTree::Cell^  cell11;
	private: DevComponents::AdvTree::Node^  node15;
	private: DevComponents::AdvTree::Node^  node13;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector8;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle8;
	private: DevComponents::DotNetBar::SuperTabItem^  recommendFocusGroup;
	private: DevComponents::DotNetBar::SuperTabControlPanel^  superTabControlPanel24;
	private: DevComponents::AdvTree::AdvTree^  advTree3;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader22;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader23;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader24;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader25;
	private: DevComponents::AdvTree::ColumnHeader^  columnHeader26;
	private: DevComponents::AdvTree::Node^  node16;
	private: DevComponents::AdvTree::NodeConnector^  nodeConnector9;
	private: DevComponents::DotNetBar::ElementStyle^  elementStyle9;
	private: DevComponents::DotNetBar::SuperTabItem^  recommendFocusUser;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RecommendFocusTab::typeid));
			this->superTabControl7 = (gcnew DevComponents::DotNetBar::SuperTabControl());
			this->superTabControlPanel21 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->advTree2 = (gcnew DevComponents::AdvTree::AdvTree());
			this->columnHeader17 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader18 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader19 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader20 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader21 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->node12 = (gcnew DevComponents::AdvTree::Node());
			this->node14 = (gcnew DevComponents::AdvTree::Node());
			this->cell9 = (gcnew DevComponents::AdvTree::Cell());
			this->cell10 = (gcnew DevComponents::AdvTree::Cell());
			this->cell12 = (gcnew DevComponents::AdvTree::Cell());
			this->cell11 = (gcnew DevComponents::AdvTree::Cell());
			this->node15 = (gcnew DevComponents::AdvTree::Node());
			this->node13 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector8 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle8 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->recommendFocusGroup = (gcnew DevComponents::DotNetBar::SuperTabItem());
			this->superTabControlPanel24 = (gcnew DevComponents::DotNetBar::SuperTabControlPanel());
			this->advTree3 = (gcnew DevComponents::AdvTree::AdvTree());
			this->columnHeader22 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader23 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader24 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader25 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->columnHeader26 = (gcnew DevComponents::AdvTree::ColumnHeader());
			this->node16 = (gcnew DevComponents::AdvTree::Node());
			this->nodeConnector9 = (gcnew DevComponents::AdvTree::NodeConnector());
			this->elementStyle9 = (gcnew DevComponents::DotNetBar::ElementStyle());
			this->recommendFocusUser = (gcnew DevComponents::DotNetBar::SuperTabItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl7))->BeginInit();
			this->superTabControl7->SuspendLayout();
			this->superTabControlPanel21->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree2))->BeginInit();
			this->superTabControlPanel24->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree3))->BeginInit();
			this->SuspendLayout();
			// 
			// superTabControl7
			// 
			// 
			// 
			// 
			// 
			// 
			// 
			this->superTabControl7->ControlBox->CloseBox->Name = L"";
			// 
			// 
			// 
			this->superTabControl7->ControlBox->MenuBox->Name = L"";
			this->superTabControl7->ControlBox->Name = L"";
			this->superTabControl7->ControlBox->SubItems->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->superTabControl7->ControlBox->MenuBox, 
				this->superTabControl7->ControlBox->CloseBox});
			this->superTabControl7->ControlBox->Visible = false;
			this->superTabControl7->Controls->Add(this->superTabControlPanel21);
			this->superTabControl7->Controls->Add(this->superTabControlPanel24);
			this->superTabControl7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControl7->FixedTabSize = System::Drawing::Size(120, 40);
			this->superTabControl7->Location = System::Drawing::Point(0, 0);
			this->superTabControl7->Name = L"superTabControl7";
			this->superTabControl7->ReorderTabsEnabled = true;
			this->superTabControl7->SelectedTabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold));
			this->superTabControl7->SelectedTabIndex = 0;
			this->superTabControl7->Size = System::Drawing::Size(585, 546);
			this->superTabControl7->TabFont = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->superTabControl7->TabIndex = 1;
			this->superTabControl7->Tabs->AddRange(gcnew cli::array< DevComponents::DotNetBar::BaseItem^  >(2) {this->recommendFocusGroup, 
				this->recommendFocusUser});
			this->superTabControl7->Text = L"superTabControl7";
			this->superTabControl7->TextAlignment = DevComponents::DotNetBar::eItemAlignment::Center;
			// 
			// superTabControlPanel21
			// 
			this->superTabControlPanel21->Controls->Add(this->advTree2);
			this->superTabControlPanel21->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel21->Location = System::Drawing::Point(0, 42);
			this->superTabControlPanel21->Name = L"superTabControlPanel21";
			this->superTabControlPanel21->Size = System::Drawing::Size(585, 504);
			this->superTabControlPanel21->TabIndex = 1;
			this->superTabControlPanel21->TabItem = this->recommendFocusGroup;
			// 
			// advTree2
			// 
			this->advTree2->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->advTree2->AllowDrop = true;
			this->advTree2->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->advTree2->BackgroundStyle->Class = L"TreeBorderKey";
			this->advTree2->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->advTree2->Columns->Add(this->columnHeader17);
			this->advTree2->Columns->Add(this->columnHeader18);
			this->advTree2->Columns->Add(this->columnHeader19);
			this->advTree2->Columns->Add(this->columnHeader20);
			this->advTree2->Columns->Add(this->columnHeader21);
			this->advTree2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->advTree2->Location = System::Drawing::Point(0, 0);
			this->advTree2->Name = L"advTree2";
			this->advTree2->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(2) {this->node12, this->node13});
			this->advTree2->NodesConnector = this->nodeConnector8;
			this->advTree2->NodeStyle = this->elementStyle8;
			this->advTree2->PathSeparator = L";";
			this->advTree2->Size = System::Drawing::Size(585, 504);
			this->advTree2->Styles->Add(this->elementStyle8);
			this->advTree2->TabIndex = 0;
			this->advTree2->Text = L"advTree2";
			// 
			// columnHeader17
			// 
			this->columnHeader17->Name = L"columnHeader17";
			this->columnHeader17->Text = L"Column";
			this->columnHeader17->Width->Absolute = 150;
			// 
			// columnHeader18
			// 
			this->columnHeader18->Name = L"columnHeader18";
			this->columnHeader18->Text = L"Column";
			this->columnHeader18->Width->Absolute = 100;
			// 
			// columnHeader19
			// 
			this->columnHeader19->Name = L"columnHeader19";
			this->columnHeader19->Text = L"Column";
			this->columnHeader19->Width->Absolute = 80;
			// 
			// columnHeader20
			// 
			this->columnHeader20->Name = L"columnHeader20";
			this->columnHeader20->Text = L"Column";
			this->columnHeader20->Width->Absolute = 100;
			// 
			// columnHeader21
			// 
			this->columnHeader21->Name = L"columnHeader21";
			this->columnHeader21->Text = L"Column";
			this->columnHeader21->Width->Absolute = 125;
			// 
			// node12
			// 
			this->node12->Expanded = true;
			this->node12->Name = L"node12";
			this->node12->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(2) {this->node14, this->node15});
			this->node12->Text = L"群组分类1";
			// 
			// node14
			// 
			this->node14->Cells->Add(this->cell9);
			this->node14->Cells->Add(this->cell10);
			this->node14->Cells->Add(this->cell12);
			this->node14->Cells->Add(this->cell11);
			this->node14->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"node14.Image")));
			this->node14->Name = L"node14";
			this->node14->Text = L"推荐关注群组1";
			// 
			// cell9
			// 
			this->cell9->Name = L"cell9";
			this->cell9->StyleMouseOver = nullptr;
			this->cell9->Text = L"群组共享文件总容量";
			// 
			// cell10
			// 
			this->cell10->Name = L"cell10";
			this->cell10->StyleMouseOver = nullptr;
			this->cell10->Text = L"群组关注人数";
			// 
			// cell12
			// 
			this->cell12->Name = L"cell12";
			this->cell12->StyleMouseOver = nullptr;
			this->cell12->Text = L"群组详细信息";
			// 
			// cell11
			// 
			this->cell11->Name = L"cell11";
			this->cell11->StyleMouseOver = nullptr;
			this->cell11->Text = L"群组关注按钮";
			// 
			// node15
			// 
			this->node15->Name = L"node15";
			this->node15->Text = L"推荐关注群组2";
			// 
			// node13
			// 
			this->node13->Name = L"node13";
			this->node13->Text = L"群组分类2";
			// 
			// nodeConnector8
			// 
			this->nodeConnector8->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle8
			// 
			this->elementStyle8->Class = L"";
			this->elementStyle8->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle8->Name = L"elementStyle8";
			this->elementStyle8->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// recommendFocusGroup
			// 
			this->recommendFocusGroup->AttachedControl = this->superTabControlPanel21;
			this->recommendFocusGroup->GlobalItem = false;
			this->recommendFocusGroup->Name = L"recommendFocusGroup";
			this->recommendFocusGroup->Text = L"推荐关注的群组";
			// 
			// superTabControlPanel24
			// 
			this->superTabControlPanel24->Controls->Add(this->advTree3);
			this->superTabControlPanel24->Dock = System::Windows::Forms::DockStyle::Fill;
			this->superTabControlPanel24->Location = System::Drawing::Point(0, 0);
			this->superTabControlPanel24->Name = L"superTabControlPanel24";
			this->superTabControlPanel24->Size = System::Drawing::Size(585, 546);
			this->superTabControlPanel24->TabIndex = 0;
			this->superTabControlPanel24->TabItem = this->recommendFocusUser;
			// 
			// advTree3
			// 
			this->advTree3->AccessibleRole = System::Windows::Forms::AccessibleRole::Outline;
			this->advTree3->AllowDrop = true;
			this->advTree3->BackColor = System::Drawing::SystemColors::Window;
			// 
			// 
			// 
			this->advTree3->BackgroundStyle->Class = L"TreeBorderKey";
			this->advTree3->BackgroundStyle->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->advTree3->Columns->Add(this->columnHeader22);
			this->advTree3->Columns->Add(this->columnHeader23);
			this->advTree3->Columns->Add(this->columnHeader24);
			this->advTree3->Columns->Add(this->columnHeader25);
			this->advTree3->Columns->Add(this->columnHeader26);
			this->advTree3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->advTree3->Location = System::Drawing::Point(0, 0);
			this->advTree3->Name = L"advTree3";
			this->advTree3->Nodes->AddRange(gcnew cli::array< DevComponents::AdvTree::Node^  >(1) {this->node16});
			this->advTree3->NodesConnector = this->nodeConnector9;
			this->advTree3->NodeStyle = this->elementStyle9;
			this->advTree3->PathSeparator = L";";
			this->advTree3->Size = System::Drawing::Size(585, 546);
			this->advTree3->Styles->Add(this->elementStyle9);
			this->advTree3->TabIndex = 1;
			this->advTree3->Text = L"advTree3";
			// 
			// columnHeader22
			// 
			this->columnHeader22->Name = L"columnHeader22";
			this->columnHeader22->Text = L"Column";
			this->columnHeader22->Width->Absolute = 150;
			// 
			// columnHeader23
			// 
			this->columnHeader23->Name = L"columnHeader23";
			this->columnHeader23->Text = L"Column";
			this->columnHeader23->Width->Absolute = 100;
			// 
			// columnHeader24
			// 
			this->columnHeader24->Name = L"columnHeader24";
			this->columnHeader24->Text = L"Column";
			this->columnHeader24->Width->Absolute = 100;
			// 
			// columnHeader25
			// 
			this->columnHeader25->Name = L"columnHeader25";
			this->columnHeader25->Text = L"Column";
			this->columnHeader25->Width->Absolute = 125;
			// 
			// columnHeader26
			// 
			this->columnHeader26->Name = L"columnHeader26";
			this->columnHeader26->Text = L"Column";
			this->columnHeader26->Width->Absolute = 125;
			// 
			// node16
			// 
			this->node16->Expanded = true;
			this->node16->Name = L"node16";
			this->node16->Text = L"推荐关注用户1";
			// 
			// nodeConnector9
			// 
			this->nodeConnector9->LineColor = System::Drawing::SystemColors::ControlText;
			// 
			// elementStyle9
			// 
			this->elementStyle9->Class = L"";
			this->elementStyle9->CornerType = DevComponents::DotNetBar::eCornerType::Square;
			this->elementStyle9->Name = L"elementStyle9";
			this->elementStyle9->TextColor = System::Drawing::SystemColors::ControlText;
			// 
			// recommendFocusUser
			// 
			this->recommendFocusUser->AttachedControl = this->superTabControlPanel24;
			this->recommendFocusUser->GlobalItem = false;
			this->recommendFocusUser->Name = L"recommendFocusUser";
			this->recommendFocusUser->Text = L"推荐关注的用户";
			// 
			// RecommendFocusTab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593,573);
			this->Controls->Add(this->superTabControl7);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"RecommendFocusTab";
			this->Text = L"RecommendFocusTab";
			
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->superTabControl7))->EndInit();
			this->superTabControl7->ResumeLayout(false);
			this->superTabControlPanel21->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree2))->EndInit();
			this->superTabControlPanel24->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->advTree3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
