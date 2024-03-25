#include "deleteForm.h"

System::Void ThirdLab::deleteForm::Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context context;
	std::string keyStr = context.marshal_as<std::string>(keyInput->Text);

	if (keyInput->Text->Length > 0) {
		try {
			int key = std::stoi(keyStr);
			if (tree->deletion(key)){
				MessageBox::Show("Value delete");
				Close();
			}
			else {
				MessageBox::Show("Value can`t delete");
			}
			
		}
		catch (std::invalid_argument iaex) {
			MessageBox::Show("Not correct number");
		}
	}
	else {
		MessageBox::Show("Enter correct long value");
	}
}
