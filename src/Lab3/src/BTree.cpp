#include "BTree.h"

namespace ThirdLab {
    BTree::BTree(int newT)
    {
        root = NULL;

        t = newT;
    }

    void BTree::traverse(std::vector<std::pair<int, std::string>>& data)
    {
        if (root != NULL)
            out.traverse(root, data);
    }

    void BTree::insertion(int k, std::string val)
    {
        if (root == NULL) {
            root = new TreeNode(t, true);
            root->keys[0] = k;
            root->values[0] = val;
            root->n = 1;
        }
        else {
            if (root->n == 2 * t - 1) {
                TreeNode* s = new TreeNode(t, false);

                s->Child[0] = root;

                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k)
                    i++;
                s->Child[i]->insertNonFull(k, val);

                root = s;
            }
            else
                root->insertNonFull(k, val);
        }

    }

    bool BTree::deletion(int k)
    {
        if (!root) {
            return false; 
        }

        bool keyExists = root->search(k) != nullptr; 
        if (!keyExists) {
            return false; 
        }

        root->deletion(k);

        if (root->n == 0) {
            TreeNode* tmp = root;
            if (root->leaf) {
                root = NULL;
            }
            else {
                root = root->Child[0];
            }
            delete tmp;
        }
        return true;
    }

    TreeNode* BTree::getNode()
    {
        return root;
    }

    TreeNode* BTree::search(int key)
    {
        if (root == NULL) {
            return NULL;
        }
        else {
            root->comparisonCount = 0;
            return root->search(key);
        }
    }
    void BTree::setKey(int key, int newKey)
    {
        int index = root->findKey(key);
        std::string value = root->getValues()[index];
        deletion(key);
        insertion(newKey, value);
    }

    void BTree::setValue(int key, std::string newValue)
    {
        int index = root->findKey(key);
        root->getValues()[index] = newValue;
    }

    void BTree::setRoot(TreeNode* newRoot)
    {
        if (root != NULL) {
            delete root; 
        }
        root = newRoot;
    }
}