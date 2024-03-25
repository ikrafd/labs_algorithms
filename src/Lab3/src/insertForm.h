#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include <stdexcept>
#include "BTree.h"

namespace ThirdLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for insertForm
	/// </summary>
	public ref class insertForm : public System::Windows::Forms::Form
	{
	public:
		insertForm(BTree* tree)
		{
			InitializeComponent();
			this->tree = tree;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~insertForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Ok;
	private:
		BTree* tree;
		System::Windows::Forms::TextBox^ keyInput;
		System::Windows::Forms::TextBox^ valueInput;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;

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
			this->Ok = (gcnew System::Windows::Forms::Button());
			this->keyInput = (gcnew System::Windows::Forms::TextBox());
			this->valueInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			
			this->Ok->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Ok->Location = System::Drawing::Point(115, 234);
			this->Ok->Name = L"Ok";
			this->Ok->Size = System::Drawing::Size(112, 47);
			this->Ok->TabIndex = 0;
			this->Ok->Text = L"OK";
			this->Ok->UseVisualStyleBackColor = true;
			this->Ok->Click += gcnew System::EventHandler(this, &insertForm::Ok_Click);
		
			this->keyInput->Location = System::Drawing::Point(115, 78);
			this->keyInput->Name = L"keyInput";
			this->keyInput->Size = System::Drawing::Size(110, 22);
			this->keyInput->TabIndex = 1;
		
			this->valueInput->Location = System::Drawing::Point(115, 164);
			this->valueInput->MaxLength = 5;
			this->valueInput->Name = L"valueInput";
			this->valueInput->Size = System::Drawing::Size(110, 22);
			this->valueInput->TabIndex = 2;
		
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(115, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Input key";
		
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(115, 131);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Input value";
			
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(358, 334);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->valueInput);
			this->Controls->Add(this->keyInput);
			this->Controls->Add(this->Ok);
			this->Name = L"insertForm";
			this->Text = L"insertForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Ok_Click(System::Object^ sender, System::EventArgs^ e);
};
}
