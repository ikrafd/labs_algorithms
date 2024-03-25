#ifndef TREENODE
#define TREENODE
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>

namespace ThirdLab {
	class TreeNode
	{
		int* keys;
		int t;
		TreeNode** Child;
		int n;
		bool leaf;
		std::string* values;

	public:
		int comparisonCount;
		TreeNode(int t1, bool boolLeaf);
		int findKey(int k);
		void insertNonFull(int k, std::string val);
		void splitChild(int i, TreeNode* y);
		void deletion(int k);
		void removeFromLeaf(int idx);
		void removeFromNonLeaf(int idx);
		int getPredecessor(int idx);
		int getSuccessor(int idx);
		void fill(int idx);
		void borrowFromPrev(int idx);
		void borrowFromNext(int idx);
		void merge(int idx);
		TreeNode* search(int k);

		int getN();
		TreeNode** getChild();
		bool getLeaf();
		int* getKey();
		std::string* getValues();
		void setKey(int key, int index);
		void setValue(std::string value, int index);
		void setN(int newN);
		void setChild(TreeNode* node, int index);

		~TreeNode();
		friend class BTree;
		friend class outputTree;
	};

	class outputTree {
	public:
		void traverse(TreeNode* , std::vector<std::pair<int, std::string>>&);
		void serialize(TreeNode*, std::ofstream&);
		TreeNode* deserializeNode(std::ifstream& in, int t);
	};
}
#endif 