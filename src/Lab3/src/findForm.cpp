#include "findForm.h"
System::Void ThirdLab::findForm::Ok_Click(System::Object^ sender, System::EventArgs^ e) {
    msclr::interop::marshal_context context;
    if (inputKey->Text->Length > 0) {
        std::string keyStr = context.marshal_as<std::string>(inputKey->Text);
        try {
            int key = std::stoi(keyStr);
            TreeNode* node = tree->search(key);
            if (node != nullptr) {
                int index = node->findKey(key);
                std::string valueStr = node->getValues()[index];
                int comparisonCount = node->comparisonCount;
                System::String^ managedValueStr = gcnew System::String(valueStr.c_str());
                System::String^ managedComparisonCountStr = comparisonCount.ToString();
                result->Text = "Result: " + managedValueStr + "\nCompare count: " + managedComparisonCountStr;
            }
            else {
                MessageBox::Show("Tree is empty or key not found.");
            }
        }
        catch (const std::invalid_argument&) {
            MessageBox::Show("The input is not a valid number.");
        }
        catch (const std::out_of_range&) {
            MessageBox::Show("The input number is out of range.");
        }
    }
    else {
        MessageBox::Show("Please enter a key to search.");
    }
}

