#ifndef PROBLEM_H  
#define PROBLEM_H 

#include <vector>

#include "Node.h"
#include <unordered_set>
#include <functional> 
using namespace std;

struct VectorHash {
	size_t operator()(const vector<int>& v) const {
		hash <int> hasher;
		size_t seed = 0;
		for (int i : v) {
			seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};

class Problem
{
protected:
	int sizeBoard;
public:
	Problem(int);
	void setSizeBoard(int);
	int heuristics(vector<int>&);
	vector<pair<int, int>> FindQueen(vector<int>&);
};

class ProblemLDFS: public Problem {
	unordered_set<vector<int>, VectorHash> parentStates;
	int statesChildCounter =0;
public:
	ProblemLDFS(int);
	vector <Node*> createChild(Node*);
	void addParentState(vector<int>);
	int getCounter();
};

class ProblemHeuristic : public Problem
{

public:
	ProblemHeuristic(int);
	vector<NodeHeuristic*> createChild(NodeHeuristic*);
};

#endif 

