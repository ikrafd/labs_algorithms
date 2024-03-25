#pragma once
#include "TreeNode.h"
namespace ThirdLab{
    class BTree {
        TreeNode* root;
        outputTree out;
        int t;

    public:
        BTree(int newT);

        void traverse(std::vector<std::pair<int, std::string>>&);

        void insertion(int k, std::string);

        bool deletion(int k);

        TreeNode* getNode();

        void setRoot(TreeNode* newRoot);

        TreeNode* BTree::search(int key);

        void BTree::setKey(int key, int newKey);

        void BTree::setValue(int key, std::string newValue);

    };
}



