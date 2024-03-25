#pragma once
#include "BTree.h"
#include <utility>
#include <string>
#include "insertForm.h"
#include "editForm.h"
#include "findForm.h"
#include "deleteForm.h"
#include "workFunction.h"
namespace ThirdLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	private:
		BTree* tree;
		int tValue;
		outputTree* outTree;
	public:
		mainForm(void)
		{
			InitializeComponent();
			tValue = 15;
			tree = new BTree(tValue);
			outTree = new outputTree;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete tree;
				delete outTree;
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private:
		System::Windows::Forms::Button^ insert;
		System::Windows::Forms::Button^ edit;
		System::Windows::Forms::Button^ find;
		System::Windows::Forms::Button^ save;
		System::Windows::Forms::Button^ delet;
		System::Windows::Forms::Button^ read;
		System::Windows::Forms::Button^ generate;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Key;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Data;

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->insert = (gcnew System::Windows::Forms::Button());
			this->edit = (gcnew System::Windows::Forms::Button());
			this->find = (gcnew System::Windows::Forms::Button());
			this->save = (gcnew System::Windows::Forms::Button());
			this->delet = (gcnew System::Windows::Forms::Button());
			this->read = (gcnew System::Windows::Forms::Button());
			this->generate = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Key = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Data = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			
			this->tableLayoutPanel1->ColumnCount = 7;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->insert, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->edit, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->find, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->save, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->delet, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->read, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->generate, 6, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(27, 31);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(712, 38);
			this->tableLayoutPanel1->TabIndex = 0;
			
			this->insert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->insert->Location = System::Drawing::Point(3, 3);
			this->insert->Name = L"insert";
			this->insert->Size = System::Drawing::Size(94, 32);
			this->insert->TabIndex = 0;
			this->insert->Text = L"Insert";
			this->insert->UseVisualStyleBackColor = true;
			this->insert->Click += gcnew System::EventHandler(this, &mainForm::insert_Click);
			
			this->edit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->edit->Location = System::Drawing::Point(103, 3);
			this->edit->Name = L"edit";
			this->edit->Size = System::Drawing::Size(94, 32);
			this->edit->TabIndex = 1;
			this->edit->Text = L"Edit";
			this->edit->UseVisualStyleBackColor = true;
			this->edit->Click += gcnew System::EventHandler(this, &mainForm::edit_Click);
			 
			this->find->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->find->Location = System::Drawing::Point(203, 3);
			this->find->Name = L"find";
			this->find->Size = System::Drawing::Size(94, 32);
			this->find->TabIndex = 2;
			this->find->Text = L"Find";
			this->find->UseVisualStyleBackColor = true;
			this->find->Click += gcnew System::EventHandler(this, &mainForm::find_Click);
			
			this->save->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->save->Location = System::Drawing::Point(403, 3);
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(94, 32);
			this->save->TabIndex = 3;
			this->save->Text = L"Save";
			this->save->UseVisualStyleBackColor = true;
			this->save->Click += gcnew System::EventHandler(this, &mainForm::save_Click);
			
			this->delet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->delet->Location = System::Drawing::Point(303, 3);
			this->delet->Name = L"delet";
			this->delet->Size = System::Drawing::Size(94, 32);
			this->delet->TabIndex = 4;
			this->delet->Text = L"Delete";
			this->delet->UseVisualStyleBackColor = true;
			this->delet->Click += gcnew System::EventHandler(this, &mainForm::delet_Click);
			 
			this->read->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->read->Location = System::Drawing::Point(503, 3);
			this->read->Name = L"read";
			this->read->Size = System::Drawing::Size(93, 32);
			this->read->TabIndex = 5;
			this->read->Text = L"Read";
			this->read->UseVisualStyleBackColor = true;
			this->read->Click += gcnew System::EventHandler(this, &mainForm::read_Click);
			
			this->generate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->generate->Location = System::Drawing::Point(603, 3);
			this->generate->Name = L"generate";
			this->generate->Size = System::Drawing::Size(104, 32);
			this->generate->TabIndex = 6;
			this->generate->Text = L"Generate";
			this->generate->UseVisualStyleBackColor = true;
			this->generate->Click += gcnew System::EventHandler(this, &mainForm::generate_Click);
			
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Key, this->Data });
			this->dataGridView1->Location = System::Drawing::Point(41, 90);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(619, 373);
			this->dataGridView1->TabIndex = 1;
			
			this->Key->HeaderText = L"Key";
			this->Key->MinimumWidth = 6;
			this->Key->Name = L"Key";
			this->Key->ReadOnly = true;
			this->Key->Width = 200;
			
			this->Data->HeaderText = L"Data";
			this->Data->MinimumWidth = 6;
			this->Data->Name = L"Data";
			this->Data->ReadOnly = true;
			this->Data->Width = 200;
			
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 672);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"mainForm";
			this->Text = L"mainForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void insert_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void edit_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void find_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void delet_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void generate_Click(System::Object^ sender, System::EventArgs^ e);

		void populateDataGridViewWithBTree();
		
		TreeNode* deserializeTree(std::ifstream& in, int t);

		void serializeTree(TreeNode* root, std::ofstream& outFile);
		
		System::Void save_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void read_Click(System::Object^ sender, System::EventArgs^ e);
};
}
