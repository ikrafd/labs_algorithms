#include "insertForm.h"

System::Void ThirdLab::insertForm::Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context context;
	std::string keyStr = context.marshal_as<std::string>(keyInput->Text);

	std::string value = context.marshal_as<std::string>(valueInput->Text);
	if (keyInput->Text->Length > 0 && valueInput->Text->Length > 0) {
		
		try {
			int key = std::stoi(keyStr);
			tree->insertion(key, value);
			MessageBox::Show("Value insert");
			Close();
		}
		catch (std::invalid_argument iaex) {
			MessageBox::Show("Not correct number");
		}
	}
	else {
		MessageBox::Show("Enter correct long value");
	}
}
