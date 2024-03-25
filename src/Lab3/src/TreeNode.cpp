#include "TreeNode.h"


namespace ThirdLab {
    TreeNode::TreeNode(int t1, bool boolLeaf) : comparisonCount(0) {
        t = t1;
        leaf = boolLeaf;

        keys = new int[2 * t - 1];
        values = new std::string[2 * t - 1];
        Child = new TreeNode * [2 * t];

        n = 0;
    }

    TreeNode* TreeNode::search(int k) {
        int i = 0;
        while (i < n && k > keys[i]) {
            comparisonCount++;
            i++;
        }

        if (keys[i] == k) {
            return this;
        }

        if (leaf == true) {
            return NULL;
        }
        Child[i]->comparisonCount = 0;
        return Child[i]->search(k);
    }

    int TreeNode::getN()
    {
        return n;
    }

    TreeNode** TreeNode::getChild()
    {
        return Child;
    }

    bool TreeNode::getLeaf()
    {
        return leaf;
    }

    int* TreeNode::getKey()
    {
        return keys;
    }

    std::string* TreeNode::getValues()
    {
        return values;
    }


    void TreeNode::insertNonFull(int k, std::string val) {
        int i = n - 1;

        if (leaf == true) {
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                values[i + 1] = values[i];
                i--;
            }

            keys[i + 1] = k;
            values[i + 1] = val;
            n = n + 1;
        }
        else {
            while (i >= 0 && keys[i] > k) {
                i--;
            }
            if (Child[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1, Child[i + 1]);

                if (keys[i + 1] < k) {
                    i++;
                }
            }
            Child[i + 1]->insertNonFull(k, val);
        }
    }

    void TreeNode::splitChild(int i, TreeNode* y) {
        TreeNode* z = new TreeNode(y->t, y->leaf);
        z->n = t - 1;

        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
            z->values[j] = y->values[j + t];
        }

        if (y->leaf == false) {
            for (int j = 0; j < t; j++) {
                z->Child[j] = y->Child[j + t];
            }
        }

        y->n = t - 1;
        for (int j = n; j >= i + 1; j--) {
            Child[j + 1] = Child[j];
        }

        Child[i + 1] = z;

        for (int j = n - 1; j >= i; j--) {
            keys[j + 1] = keys[j];
            values[j + 1] = values[j];
        }

        keys[i] = y->keys[t - 1];
        values[i] = y->values[t - 1];
        n = n + 1;
    }

    int TreeNode::findKey(int k) {
        int idx = 0;
        while (idx < n && keys[idx] < k) {
            ++idx;
        }
        return idx;
    }


    void TreeNode::deletion(int k) {
        int idx = findKey(k);

            if (idx < n && keys[idx] == k) {
                if (leaf) {
                    removeFromLeaf(idx);
                }
                else {
                    removeFromNonLeaf(idx);
                }
            }
            else {
                if (leaf) {
                    return;
                }

                bool flag = ((idx == n) ? true : false);

                if (Child[idx]->n < t) {
                    fill(idx);
                }

                if (flag && idx > n) {
                    Child[idx - 1]->deletion(k);
                }
                else {
                    Child[idx]->deletion(k);
                }
            }
        return;
    }

    void TreeNode::removeFromLeaf(int idx) {
        for (int i = idx + 1; i < n; ++i) {
            keys[i - 1] = keys[i];
            values[i - 1] = values[i];
        }

        n--;

        return;
    }

    void TreeNode::removeFromNonLeaf(int idx) {
        int k = keys[idx];

        if (Child[idx]->n >= t) {
            int pred = getPredecessor(idx);
            keys[idx] = pred;
            Child[idx]->deletion(pred);
        }

        else if (Child[idx + 1]->n >= t) {
            int succ = getSuccessor(idx);
            keys[idx] = succ;
            Child[idx + 1]->deletion(succ);
        }

        else {
            merge(idx);
            Child[idx]->deletion(k);
        }
        return;
    }

    int TreeNode::getPredecessor(int idx) {
        TreeNode* cur = Child[idx];
        while (!cur->leaf) {
            cur = cur->Child[cur->n];
        }
        return cur->keys[cur->n - 1];
    }

    int TreeNode::getSuccessor(int idx) {
        TreeNode* cur = Child[idx + 1];
        while (!cur->leaf) {
            cur = cur->Child[0];
        }
        return cur->keys[0];
    }

    void TreeNode::fill(int idx) {
        if (idx != 0 && Child[idx - 1]->n >= t) {
            borrowFromPrev(idx);

        }
        else if (idx != n && Child[idx + 1]->n >= t) {
            borrowFromNext(idx);
        }
        else {
            if (idx != n)
                merge(idx);
            else
                merge(idx - 1);
        }
        return;
    }

    void TreeNode::borrowFromPrev(int idx) {
        TreeNode* child = Child[idx];
        TreeNode* sibling = Child[idx - 1];

        for (int i = child->n - 1; i >= 0; --i) {
            child->keys[i + 1] = child->keys[i];
        }

        if (!child->leaf) {
            for (int i = child->n; i >= 0; --i) {
                child->Child[i + 1] = child->Child[i];
                child->values[0] = sibling->values[sibling->n - 1];
            }
        }

        child->keys[0] = keys[idx - 1];

        if (!child->leaf) {
            child->Child[0] = sibling->Child[sibling->n];
        }

        keys[idx - 1] = sibling->keys[sibling->n - 1];
        values[idx - 1] = sibling->values[sibling->n - 1];

        child->n += 1;
        sibling->n -= 1;

        return;
    }

    void TreeNode::borrowFromNext(int idx) {
        TreeNode* child = Child[idx];
        TreeNode* sibling = Child[idx + 1];

        child->keys[(child->n)] = keys[idx];

        if (!(child->leaf)) {
            child->Child[(child->n) + 1] = sibling->Child[0];
            child->values[child->n] = sibling->values[0];
        }

        keys[idx] = sibling->keys[0];
        values[idx] = sibling->values[0];

        for (int i = 1; i < sibling->n; ++i) {
            sibling->keys[i - 1] = sibling->keys[i];
        }

        if (!sibling->leaf) {
            for (int i = 1; i <= sibling->n; ++i)
                sibling->Child[i - 1] = sibling->Child[i];
        }

        child->n += 1;
        sibling->n -= 1;

        return;
    }

    void TreeNode::merge(int idx) {
        TreeNode* child = Child[idx];
        TreeNode* sibling = Child[idx + 1];

        child->keys[t - 1] = keys[idx];
        child->values[t - 1] = values[idx];

        for (int i = 0; i < sibling->n; ++i) {
            child->keys[i + t] = sibling->keys[i];
            child->values[i + t] = sibling->values[i];
        }
            if (!child->leaf) {
                for (int i = 0; i <= sibling->n; ++i) {
                    child->Child[i + t] = sibling->Child[i];
                }
            }

        for (int i = idx + 1; i < n; ++i) {
            keys[i - 1] = keys[i];
        }

        for (int i = idx + 2; i <= n; ++i) {
            Child[i - 1] = Child[i];
        }

        child->n += sibling->n + 1;
        n--;

        delete (sibling);
        return;
    }

    void TreeNode::setKey(int key, int index)
    {
        keys[index] = key;
    }
    void TreeNode::setValue(std::string value, int index)
    {
        values[index] = value;
    }
    
    void TreeNode::setN(int newN)
    {
        n = newN;
    }
    void TreeNode::setChild(TreeNode* node, int index)
    {
        Child[index] = node;
    }
    

    TreeNode::~TreeNode()
    {
        delete[] keys;
        delete[] values;
        if (Child[0] != nullptr) {
            for (int i = 0; i < 2 * t; i++) {
                delete Child[i];
            }
        }
        delete[] Child;
    }

    void outputTree::traverse(TreeNode* node, std::vector<std::pair<int, std::string>>& data) {
        int i;
        for (i = 0; i < node->n; i++) {
            if (!node->leaf) {
                traverse(node->Child[i], data);
            }
            data.emplace_back(node->keys[i], node->values[i]);
        }
        if (!node->leaf) {
           traverse(node->Child[i], data);
        }
    }

    void outputTree::serialize(TreeNode* node, std::ofstream& out) {
        out.write(reinterpret_cast<char*>(&node->n), sizeof(node->n));
        out.write(reinterpret_cast<char*>(&node->leaf), sizeof(node->leaf));
        for (int i = 0; i < node->n; ++i) {
            out.write(reinterpret_cast<char*>(&node->keys[i]), sizeof(int));
            out.write(node->values[i].c_str(), node->values[i].size() + 1);
        }
    }

    TreeNode* outputTree::deserializeNode(std::ifstream& in, int t)
    {
        int n;
        bool leaf;

        in.read(reinterpret_cast<char*>(&n), sizeof(n));
        in.read(reinterpret_cast<char*>(&leaf), sizeof(leaf));

        TreeNode* node = new TreeNode(t, leaf);
        node->setN(n);

        for (int i = 0; i < n; ++i) {
            int key;
            std::string value;

            in.read(reinterpret_cast<char*>(&key), sizeof(int));
            std::getline(in, value, '\0');

            node->setKey(key, i);
            node->setValue(value, i);
        }

        return node;
    }
}