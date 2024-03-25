#pragma once
#include "BTree.h"
#include "TreeNode.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <set>

class workFunction
{
public:
    std::string workFile = "tree.dat";
    std::string generateRandomString(size_t length);
    int generateUniqueInt(std::set<int>& uniqueInts, int min, int max);
};