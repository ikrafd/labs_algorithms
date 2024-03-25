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
	/// Summary for findForm
	/// </summary>
	public ref class findForm : public System::Windows::Forms::Form
	{
	public:
		findForm(BTree* tree)
		{
			InitializeComponent();
			this->tree = tree;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~findForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: 
		BTree* tree;
		System::Windows::Forms::TextBox^ inputKey;
		System::Windows::Forms::Button^ Ok;
		System::Windows::Forms::Label^ result;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inputKey = (gcnew System::Windows::Forms::TextBox());
			this->Ok = (gcnew System::Windows::Forms::Button());
			this->result = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label1->Location = System::Drawing::Point(104, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter key for find";
			
			this->inputKey->Location = System::Drawing::Point(107, 102);
			this->inputKey->Name = L"inputKey";
			this->inputKey->Size = System::Drawing::Size(114, 22);
			this->inputKey->TabIndex = 1;
		
			this->Ok->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Ok->Location = System::Drawing::Point(107, 157);
			this->Ok->Name = L"Ok";
			this->Ok->Size = System::Drawing::Size(119, 47);
			this->Ok->TabIndex = 4;
			this->Ok->Text = L"OK";
			this->Ok->UseVisualStyleBackColor = true;
			this->Ok->Click += gcnew System::EventHandler(this, &findForm::Ok_Click);
			
			this->result->AutoSize = true;
			this->result->Location = System::Drawing::Point(94, 229);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(0, 16);
			this->result->TabIndex = 5;
		
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(333, 301);
			this->Controls->Add(this->result);
			this->Controls->Add(this->inputKey);
			this->Controls->Add(this->Ok);
			this->Controls->Add(this->label1);
			this->Name = L"findForm";
			this->Text = L"findForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Ok_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
