#include "miniMax.h"
#include <list>

namespace SixthLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	
	/// <summary>
	/// Summary for mainWin
	/// </summary>
	/// 
	public ref class ComponentState {
	public:
		System::Drawing::Point Location;

		ComponentState(System::Windows::Forms::Control^ control) {
			Location = control->Location;
		}

	};

	public ref class mainWin : public System::Windows::Forms::Form
	{
	public:
		mainWin(void)
		{
			InitializeComponent();
			algo = new miniMax();
			position->Add(-1);
			position->Add(-1);
			position->Add(-1);
			position->Add(-1);
			
		}

	protected:
		
		List<int>^ position = gcnew List<int>();

		List<int>^ initialPosition = gcnew List<int>(position);

		bool firstGo = false ;
	private: System::Windows::Forms::Button^ start;
	protected:
		miniMax* algo;
		~mainWin()
		{
			if (components)
			{
				delete components;
				delete algo;
				delete position;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ Black1;
	private: System::Windows::Forms::PictureBox^ White1;



	private: System::Windows::Forms::PictureBox^ Black2;
	private: System::Windows::Forms::PictureBox^ Black3;
	private: System::Windows::Forms::PictureBox^ Black4;
	private: System::Windows::Forms::PictureBox^ White2;
	private: System::Windows::Forms::PictureBox^ White3;
	private: System::Windows::Forms::PictureBox^ White4;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel10;

	private: System::Windows::Forms::Panel^ panel9;

	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel7;

	private: System::Windows::Forms::Panel^ panel6;

	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::Panel^ panel14;
	private: System::Windows::Forms::Panel^ panel15;
	private: System::Windows::Forms::Panel^ panel16;
	private: System::Windows::Forms::Panel^ panel17;
	private: System::Windows::Forms::Panel^ panel18;
	private: System::Windows::Forms::Panel^ panel19;
	private: System::Windows::Forms::Panel^ panel20;
	private: System::Windows::Forms::Panel^ panel21;
	private: System::Windows::Forms::Panel^ panel22;
	private: System::Windows::Forms::Panel^ panel23;
	private: System::Windows::Forms::Panel^ panel24;
	private: System::Windows::Forms::Panel^ panel25;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainWin::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Black1 = (gcnew System::Windows::Forms::PictureBox());
			this->White1 = (gcnew System::Windows::Forms::PictureBox());
			this->Black2 = (gcnew System::Windows::Forms::PictureBox());
			this->Black3 = (gcnew System::Windows::Forms::PictureBox());
			this->Black4 = (gcnew System::Windows::Forms::PictureBox());
			this->White2 = (gcnew System::Windows::Forms::PictureBox());
			this->White3 = (gcnew System::Windows::Forms::PictureBox());
			this->White4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->start = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Black1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->White1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Black2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Black3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Black4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->White2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->White3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->White4))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(123, 119);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(78, 68);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// Black1
			// 
			this->Black1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black1.Image")));
			this->Black1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black1.InitialImage")));
			this->Black1->Location = System::Drawing::Point(12, 142);
			this->Black1->Name = L"Black1";
			this->Black1->Size = System::Drawing::Size(70, 61);
			this->Black1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Black1->TabIndex = 19;
			this->Black1->TabStop = false;
			this->Black1->Click += gcnew System::EventHandler(this, &mainWin::piece_Click);
			// 
			// White1
			// 
			this->White1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White1.Image")));
			this->White1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White1.InitialImage")));
			this->White1->Location = System::Drawing::Point(580, 142);
			this->White1->Name = L"White1";
			this->White1->Size = System::Drawing::Size(70, 61);
			this->White1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->White1->TabIndex = 20;
			this->White1->TabStop = false;
			this->White1->Click += gcnew System::EventHandler(this, &mainWin::piece_Click);
			// 
			// Black2
			// 
			this->Black2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black2.BackgroundImage")));
			this->Black2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black2.Image")));
			this->Black2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black2.InitialImage")));
			this->Black2->Location = System::Drawing::Point(12, 209);
			this->Black2->Name = L"Black2";
			this->Black2->Size = System::Drawing::Size(70, 61);
			this->Black2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Black2->TabIndex = 21;
			this->Black2->TabStop = false;
			this->Black2->Click += gcnew System::EventHandler(this, &mainWin::piece_Click);
			// 
			// Black3
			// 
			this->Black3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black3.BackgroundImage")));
			this->Black3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black3.Image")));
			this->Black3->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black3.InitialImage")));
			this->Black3->Location = System::Drawing::Point(12, 276);
			this->Black3->Name = L"Black3";
			this->Black3->Size = System::Drawing::Size(70, 61);
			this->Black3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Black3->TabIndex = 22;
			this->Black3->TabStop = false;
			this->Black3->Click += gcnew System::EventHandler(this, &mainWin::piece_Click);
			// 
			// Black4
			// 
			this->Black4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black4.BackgroundImage")));
			this->Black4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black4.Image")));
			this->Black4->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Black4.InitialImage")));
			this->Black4->Location = System::Drawing::Point(12, 346);
			this->Black4->Name = L"Black4";
			this->Black4->Size = System::Drawing::Size(70, 61);
			this->Black4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Black4->TabIndex = 23;
			this->Black4->TabStop = false;
			this->Black4->Click += gcnew System::EventHandler(this, &mainWin::piece_Click);
			// 
			// White2
			// 
			this->White2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White2.BackgroundImage")));
			this->White2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White2.Image")));
			this->White2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White2.InitialImage")));
			this->White2->Location = System::Drawing::Point(580, 209);
			this->White2->Name = L"White2";
			this->White2->Size = System::Drawing::Size(70, 61);
			this->White2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->White2->TabIndex = 24;
			this->White2->TabStop = false;
			this->White2->Click += gcnew System::EventHandler(this, &mainWin::piece_Click);
			// 
			// White3
			// 
			this->White3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White3.BackgroundImage")));
			this->White3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White3.Image")));
			this->White3->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White3.InitialImage")));
			this->White3->Location = System::Drawing::Point(580, 276);
			this->White3->Name = L"White3";
			this->White3->Size = System::Drawing::Size(70, 61);
			this->White3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->White3->TabIndex = 25;
			this->White3->TabStop = false;
			this->White3->Click += gcnew System::EventHandler(this, &mainWin::piece_Click);
			// 
			// White4
			// 
			this->White4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White4.BackgroundImage")));
			this->White4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White4.Image")));
			this->White4->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"White4.InitialImage")));
			this->White4->Location = System::Drawing::Point(580, 343);
			this->White4->Name = L"White4";
			this->White4->Size = System::Drawing::Size(70, 61);
			this->White4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->White4->TabIndex = 26;
			this->White4->TabStop = false;
			this->White4->Click += gcnew System::EventHandler(this, &mainWin::piece_Click);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Location = System::Drawing::Point(207, 119);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(78, 68);
			this->panel2->TabIndex = 1;
			this->panel2->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Location = System::Drawing::Point(291, 119);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(78, 68);
			this->panel3->TabIndex = 27;
			this->panel3->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Location = System::Drawing::Point(375, 119);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(78, 68);
			this->panel4->TabIndex = 28;
			this->panel4->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Location = System::Drawing::Point(459, 119);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(78, 68);
			this->panel5->TabIndex = 29;
			this->panel5->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel10
			// 
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel10->Location = System::Drawing::Point(459, 193);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(78, 68);
			this->panel10->TabIndex = 34;
			this->panel10->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel9
			// 
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->Location = System::Drawing::Point(375, 193);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(78, 68);
			this->panel9->TabIndex = 33;
			this->panel9->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel8
			// 
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Location = System::Drawing::Point(291, 193);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(78, 68);
			this->panel8->TabIndex = 32;
			this->panel8->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Location = System::Drawing::Point(207, 193);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(78, 68);
			this->panel7->TabIndex = 31;
			this->panel7->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Location = System::Drawing::Point(123, 193);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(78, 68);
			this->panel6->TabIndex = 30;
			this->panel6->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel11
			// 
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel11->Location = System::Drawing::Point(123, 266);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(78, 68);
			this->panel11->TabIndex = 39;
			this->panel11->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel12
			// 
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel12->Location = System::Drawing::Point(208, 266);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(78, 68);
			this->panel12->TabIndex = 38;
			this->panel12->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel13
			// 
			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel13->Location = System::Drawing::Point(291, 267);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(78, 68);
			this->panel13->TabIndex = 37;
			this->panel13->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel14
			// 
			this->panel14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel14->Location = System::Drawing::Point(375, 266);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(78, 68);
			this->panel14->TabIndex = 36;
			this->panel14->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel15
			// 
			this->panel15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel15->Location = System::Drawing::Point(460, 266);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(78, 68);
			this->panel15->TabIndex = 35;
			this->panel15->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel16
			// 
			this->panel16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel16->Location = System::Drawing::Point(123, 340);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(78, 68);
			this->panel16->TabIndex = 44;
			this->panel16->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel17
			// 
			this->panel17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel17->Location = System::Drawing::Point(207, 340);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(78, 68);
			this->panel17->TabIndex = 43;
			this->panel17->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel18
			// 
			this->panel18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel18->Location = System::Drawing::Point(292, 340);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(78, 68);
			this->panel18->TabIndex = 42;
			this->panel18->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel19
			// 
			this->panel19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel19->Location = System::Drawing::Point(375, 339);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(78, 68);
			this->panel19->TabIndex = 41;
			this->panel19->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel20
			// 
			this->panel20->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel20->Location = System::Drawing::Point(460, 339);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(78, 68);
			this->panel20->TabIndex = 40;
			this->panel20->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel21
			// 
			this->panel21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel21->Location = System::Drawing::Point(123, 414);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(78, 68);
			this->panel21->TabIndex = 49;
			this->panel21->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel22
			// 
			this->panel22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel22->Location = System::Drawing::Point(208, 414);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(78, 68);
			this->panel22->TabIndex = 48;
			this->panel22->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel23
			// 
			this->panel23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel23->Location = System::Drawing::Point(291, 414);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(78, 68);
			this->panel23->TabIndex = 47;
			this->panel23->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel24
			// 
			this->panel24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel24->Location = System::Drawing::Point(375, 414);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(78, 68);
			this->panel24->TabIndex = 46;
			this->panel24->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// panel25
			// 
			this->panel25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel25->Location = System::Drawing::Point(460, 414);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(78, 68);
			this->panel25->TabIndex = 45;
			this->panel25->Click += gcnew System::EventHandler(this, &mainWin::panel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(443, 534);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 50;
			// 
			// start
			// 
			this->start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->start->Location = System::Drawing::Point(264, 29);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(116, 52);
			this->start->TabIndex = 51;
			this->start->Text = L"Start game";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &mainWin::start_Click);
			// 
			// mainWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(662, 596);
			this->Controls->Add(this->start);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->White1);
			this->Controls->Add(this->White4);
			this->Controls->Add(this->White3);
			this->Controls->Add(this->White2);
			this->Controls->Add(this->Black4);
			this->Controls->Add(this->Black3);
			this->Controls->Add(this->Black2);
			this->Controls->Add(this->Black1);
			this->Controls->Add(this->panel21);
			this->Controls->Add(this->panel22);
			this->Controls->Add(this->panel23);
			this->Controls->Add(this->panel24);
			this->Controls->Add(this->panel25);
			this->Controls->Add(this->panel16);
			this->Controls->Add(this->panel17);
			this->Controls->Add(this->panel18);
			this->Controls->Add(this->panel19);
			this->Controls->Add(this->panel20);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->panel12);
			this->Controls->Add(this->panel13);
			this->Controls->Add(this->panel14);
			this->Controls->Add(this->panel15);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel10);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel7);
			this->Name = L"mainWin";
			this->Text = L"mainWin";
			this->Load += gcnew System::EventHandler(this, &mainWin::mainWin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Black1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->White1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Black2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Black3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Black4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->White2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->White3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->White4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
			SaveInitialState();
	


		}
#pragma endregion
	private: System::Void mainWin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Windows::Forms::PictureBox^ selectedPiece = nullptr;

private: System::Void piece_Click(System::Object^ sender, System::EventArgs^ e) {
	selectedPiece = safe_cast<PictureBox^>(sender);
}

private: System::Void panel_Click(System::Object^ sender, System::EventArgs^ e) {
	if (selectedPiece != nullptr) {

		Panel^ targetPanel = safe_cast<Panel^>(sender);

		String^ panelName = targetPanel->Name;
		String^ panelNumber = panelName->Substring(5);
		int panelIndex = System::Int32::Parse(panelNumber);
		String^ panelColor = selectedPiece->Name->Substring(0,5);
		if (panelColor == "White") {
			MessageBox::Show("Can`t move white");
			return;
		}

		if (algo->getValueBoard(panelIndex-1) == 0) {
			selectedPiece->Location = Point(targetPanel->Location.X + (targetPanel->Width - selectedPiece->Width) / 2,
				targetPanel->Location.Y + (targetPanel->Height - selectedPiece->Height) / 2);

			String^ panelName = targetPanel->Name;
			String^ panelNumber = panelName->Substring(5);
			int panelIndex = System::Int32::Parse(panelNumber);
			String^ cardNumS = selectedPiece->Name->Substring(5, 1);

			int cardNum= System::Int32::Parse(cardNumS);;
			
			algo->updateBoard(position[cardNum-1], panelIndex);
			position[cardNum-1] = panelIndex;
			firstGo = true;
			
		}
		else {
			MessageBox::Show("You can`t move to panel" + panelIndex);
		}
		selectedPiece = nullptr;
	}
}

private: System::Void start_Click(System::Object^ sender, System::EventArgs^ e) {
	cleanBoard();
	bool itIsOver = algo->checkOver();
	while (!itIsOver) {
		List<int>^ previousPosition = gcnew List<int>(position); 
		label1->Text = "Plese make move";
		while (!HasPositionChanged(previousPosition, position)) {
			Application::DoEvents();
		}
		
		algo->setPlayer(2);
		label1->Text = "Computer go";
		moveWhite();
		
		algo->setPlayer(1);
		itIsOver = algo->checkOver();
		
	}
	MessageBox::Show("Player "+ algo->getPlayer()+" was won");
	label1->Text = "Player " + algo->getPlayer() + " was won";
}
	 bool HasPositionChanged(List<int>^ previous, List<int>^ current) {

		   for (int i = 0; i < previous->Count; i++) {
			   if (previous[i] != current[i]) {
				   return true; 
			   }
		   }

		   return false; 
	   }

	 void moveWhite() {
		 auto plase = algo->move();
		 PictureBox^ pictureBox = nullptr;
		 Panel^ panel = nullptr;

		 switch (plase.second) {
		 case 1:
			 pictureBox = White1;
			 break;
		 case 2:
			 pictureBox = White2;
			 break;
		 case 3:
			 pictureBox = White3;
			 break;
		 case 4:
			 pictureBox = White4;
			 break;
		 }

		 plase.first += 1;
		 String^ panelName = "panel" + plase.first;
		 panel = safe_cast<Panel^>(Controls->Find(panelName, true)[0]);
		 

		 if (pictureBox != nullptr && panel != nullptr) {
			 pictureBox->Location = Point(panel->Location.X + (panel->Width - pictureBox->Width) / 2,
				 panel->Location.Y + (panel->Height - pictureBox->Height) / 2);
		 }
	 }
	 private: System::Collections::Generic::Dictionary<System::String^, ComponentState^> initialState;

private: void SaveInitialState() {
	
	initialState["Black1"] = gcnew ComponentState(this->Black1);
	initialState["Black2"] = gcnew ComponentState(this->Black2);
	initialState["Black3"] = gcnew ComponentState(this->Black3);
	initialState["Black4"] = gcnew ComponentState(this->Black4);
	initialState["White1"] = gcnew ComponentState(this->White1);
	initialState["White2"] = gcnew ComponentState(this->White2);
	initialState["White3"] = gcnew ComponentState(this->White3);
	initialState["White4"] = gcnew ComponentState(this->White4);

}

	 void cleanBoard() {
		 algo->clearBoard();
		 position->Clear();
		 position->Add(-1);
		 position->Add(-1);
		 position->Add(-1);
		 position->Add(-1);
		
		 this->Black1->Location = initialState["Black1"]->Location;
		 this->Black2->Location = initialState["Black2"]->Location;
		 this->Black3->Location = initialState["Black3"]->Location;
		 this->Black4->Location = initialState["Black4"]->Location;
		 this->White1->Location = initialState["White1"]->Location;
		 this->White2->Location = initialState["White2"]->Location;
		 this->White3->Location = initialState["White3"]->Location;
		 this->White4->Location = initialState["White4"]->Location;

	 }


};
}
