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
	/// Summary for deleteForm
	/// </summary>
	public ref class deleteForm : public System::Windows::Forms::Form
	{
	public:
		deleteForm(BTree* tree)
		{
			InitializeComponent();
			this->tree = tree;
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~deleteForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		BTree* tree;
		System::Windows::Forms::Button^ Ok;
		System::Windows::Forms::TextBox^ keyInput;
		System::Windows::Forms::Label^ label1;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			
			this->Ok->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Ok->Location = System::Drawing::Point(92, 167);
			this->Ok->Name = L"Ok";
			this->Ok->Size = System::Drawing::Size(112, 47);
			this->Ok->TabIndex = 1;
			this->Ok->Text = L"OK";
			this->Ok->UseVisualStyleBackColor = true;
			this->Ok->Click += gcnew System::EventHandler(this, &deleteForm::Ok_Click);
		
			this->keyInput->Location = System::Drawing::Point(92, 114);
			this->keyInput->Name = L"keyInput";
			this->keyInput->Size = System::Drawing::Size(111, 22);
			this->keyInput->TabIndex = 2;
			
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(89, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter key for delete";
			
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(328, 300);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->keyInput);
			this->Controls->Add(this->Ok);
			this->Name = L"deleteForm";
			this->Text = L"deleteForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Ok_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
