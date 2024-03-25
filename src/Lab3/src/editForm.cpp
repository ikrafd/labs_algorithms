#include "editForm.h"

 
System::Void ThirdLab::editForm::Ok_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		msclr::interop::marshal_context context;
		std::string curKeyStr = context.marshal_as<std::string>(currentKey->Text);

		if (currentKey->Text->Length > 0 && (newKey->Text->Length > 0 || newValue->Text->Length > 0)) {
			try {
				int curKey = std::stoi(curKeyStr);

				TreeNode* node = tree->search(curKey);
				if (!node) {
					MessageBox::Show("Key does not exist in the tree.");
					Close();
					return;
				}
				int newKeyInt; 
				bool keyChanged = newKey->Text->Length > 0;
				bool valueChanged = newValue->Text->Length > 0;

				if (keyChanged) {
					newKeyInt = std::stoi(context.marshal_as<std::string>(newKey->Text));
				}

				if (keyChanged && valueChanged) {
					tree->setValue(curKey, context.marshal_as<std::string>(newValue->Text));
					tree->setKey(curKey, newKeyInt);
					MessageBox::Show("Key and value was change");
				}
				else if (keyChanged) {
					tree->setKey(curKey, newKeyInt);
					MessageBox::Show("Key was change");
				}
				else if (valueChanged) {
					tree->setValue(curKey, context.marshal_as<std::string>(newValue->Text));
					MessageBox::Show("Value was change");
				}

				Close(); 
			}
			catch (const std::invalid_argument&) {
				MessageBox::Show("The provided key is not a valid number.");
			}
			catch (const std::out_of_range&) {
				MessageBox::Show("The provided key is out of range.");
			}
		}
		else {
			MessageBox::Show("Please enter a current key and/or a new key/value.");
		}
}
