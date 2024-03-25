#include "mainForm.h"

using namespace System;
using namespace System::Windows::Forms;
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ThirdLab::mainForm form;
	Application::Run(% form);
}

System::Void ThirdLab::mainForm::insert_Click(System::Object^ sender, System::EventArgs^ e)
{
	insertForm^ form = gcnew insertForm(tree);
	form->ShowDialog();
	populateDataGridViewWithBTree();
}

System::Void ThirdLab::mainForm::edit_Click(System::Object^ sender, System::EventArgs^ e)
{
	editForm^ form = gcnew editForm(tree);
	form->ShowDialog();
	populateDataGridViewWithBTree();

}

System::Void ThirdLab::mainForm::find_Click(System::Object^ sender, System::EventArgs^ e)
{
	findForm^ form = gcnew findForm(tree);
	form->ShowDialog();

}

System::Void ThirdLab::mainForm::delet_Click(System::Object^ sender, System::EventArgs^ e)
{
	deleteForm^ form = gcnew deleteForm(tree);
	form->ShowDialog();
	populateDataGridViewWithBTree();
}

System::Void ThirdLab::mainForm::generate_Click(System::Object^ sender, System::EventArgs^ e)
{
	workFunction work;
	std::srand(std::time(nullptr));

	std::set<int> uniqueIntegers;
	const size_t NUM_PAIRS = 100;

	for (size_t i = 0; i < NUM_PAIRS; i++) {
		std::string str = work.generateRandomString(5);
		int uniqueInt = work.generateUniqueInt(uniqueIntegers, 1, 10000);
		tree->insertion(uniqueInt, str);
	}
	populateDataGridViewWithBTree();
}

void ThirdLab::mainForm::populateDataGridViewWithBTree()
{
	std::vector<std::pair<int, std::string>> data;
	tree->traverse(data);
	dataGridView1->Rows->Clear();

	for (auto element : data)
	{
		dataGridView1->Rows->Add(gcnew System::String(std::to_string(element.first).c_str()),
			gcnew System::String(element.second.c_str()));
	}
}


ThirdLab::TreeNode* ThirdLab::mainForm::deserializeTree(std::ifstream& in, int t)
{
	if (in.peek() == EOF) {
		return nullptr;
	}

	TreeNode* node = outTree->deserializeNode(in, t);

	if (!node->getLeaf()) {
		for (int i = 0; i <= node->getN(); ++i) {
			node->setChild(deserializeTree(in, t), i);
		}
	}

	return node;
}

void ThirdLab::mainForm::serializeTree(TreeNode* root, std::ofstream& outFile)
{
	if (root == nullptr) {
		return;
	}

	outTree->serialize(root, outFile);

	if (!root->getLeaf()) {
		for (int i = 0; i <= root->getN(); ++i) {
			serializeTree(root->getChild()[i], outFile);
		}
	}
}

System::Void ThirdLab::mainForm::save_Click(System::Object^ sender, System::EventArgs^ e)
{
	workFunction work;
	std::ofstream outFile(work.workFile, std::ios::binary);
	serializeTree(tree->getNode(), outFile);
	outFile.close();
	MessageBox::Show("Data was save");
}

System::Void ThirdLab::mainForm::read_Click(System::Object^ sender, System::EventArgs^ e)
{
	workFunction work;
	std::ifstream inFile(work.workFile, std::ios::binary);
	TreeNode* rootNew = deserializeTree(inFile, tValue);
	tree->setRoot(rootNew);
	inFile.close();
	populateDataGridViewWithBTree();
}

