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
	/// Summary for editForm
	/// </summary>
	public ref class editForm : public System::Windows::Forms::Form
	{
	public:
		editForm(BTree* tree)
		{
			InitializeComponent();
			this->tree = tree;
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~editForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ currentKey;
	protected:
	private:
		BTree* tree;
		System::Windows::Forms::TextBox^ newKey;
		System::Windows::Forms::TextBox^ newValue;
		System::Windows::Forms::Button^ Ok;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;

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
			this->currentKey = (gcnew System::Windows::Forms::TextBox());
			this->newKey = (gcnew System::Windows::Forms::TextBox());
			this->newValue = (gcnew System::Windows::Forms::TextBox());
			this->Ok = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			
			this->currentKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->currentKey->Location = System::Drawing::Point(284, 43);
			this->currentKey->Name = L"currentKey";
			this->currentKey->Size = System::Drawing::Size(112, 26);
			this->currentKey->TabIndex = 0;
			
			this->newKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->newKey->Location = System::Drawing::Point(284, 110);
			this->newKey->Name = L"newKey";
			this->newKey->Size = System::Drawing::Size(108, 26);
			this->newKey->TabIndex = 1;
			
			this->newValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->newValue->Location = System::Drawing::Point(284, 183);
			this->newValue->MaxLength = 5;
			this->newValue->Name = L"newValue";
			this->newValue->Size = System::Drawing::Size(108, 26);
			this->newValue->TabIndex = 2;
			
			this->Ok->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Ok->Location = System::Drawing::Point(160, 296);
			this->Ok->Name = L"Ok";
			this->Ok->Size = System::Drawing::Size(119, 47);
			this->Ok->TabIndex = 3;
			this->Ok->Text = L"OK";
			this->Ok->UseVisualStyleBackColor = true;
			this->Ok->Click += gcnew System::EventHandler(this, &editForm::Ok_Click);
			 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->label1->Location = System::Drawing::Point(19, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Enter key value for change";
			
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->label2->Location = System::Drawing::Point(19, 116);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Enter new key (optional)";
			
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->label3->Location = System::Drawing::Point(19, 189);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(160, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Enter new value (optional)";
			
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(461, 413);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Ok);
			this->Controls->Add(this->newValue);
			this->Controls->Add(this->newKey);
			this->Controls->Add(this->currentKey);
			this->Name = L"editForm";
			this->Text = L"editForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Ok_Click(System::Object^ sender, System::EventArgs^ e);
};
}
