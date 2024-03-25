#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\src\TreeNode.cpp"
#include "..\..\src\BTree.cpp"

using namespace ThirdLab;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3Tests
{
	TEST_CLASS(Lab3Tests)
	{
	public:
		
		TEST_METHOD(PositiveTest)
		{
			int t = 15;
			BTree tree(t);
			int key = 5;
			std::string expectedValue = "djfrt";
			tree.insertion(key, expectedValue);
			ThirdLab::TreeNode* node = tree.search(key);
			std::string value = node->getValues()[0];


			Assert::AreEqual(value, expectedValue);
		}

		TEST_METHOD(BoundaryTest)
		{
			int t = 3;
			BTree tree(t);
			int key = 5;

			TreeNode* node = tree.search(key);

			Assert::IsNull(node);
		}

		TEST_METHOD(NegativeTest)
		{
			int t = 3;
			BTree tree(t);
			int key = 5;

			bool deleteResult = tree.deletion(key);

			Assert::AreEqual(deleteResult, false);
		}
	
	};
}
