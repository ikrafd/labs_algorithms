#ifndef RBFS_H  
#define RBFS_H 

#include <vector>
#include <algorithm>
#include "Node.h"
#include "Problem.h"
using namespace std;

class RBFS {
	NodeHeuristic* solutionNode;
	vector<NodeHeuristic*> allNode;
	void sortChild(vector<NodeHeuristic*>*);
	bool solutionFound = false;
	int iterationCount = 0;
	int deadEndCount = 0;
	int totalStates = 0;
	int statesInMemory = 0;
public:
	int RecursiveBestFirstSearch(NodeHeuristic*, ProblemHeuristic* , int);
	void outputSolution();
	void cleanNode();
	bool getSolutionFound();
	void outputCounter();
};

#endif