#ifndef LDFS_H  
#define LDFS_H

#include "Node.h"
#include "Problem.h"
#include <stack>

class LDFS {
		Node* solutionNode;
		stack <Node*> stackNode;
		int iterationCount = 0;
		int deadEndCount = 0;
		int statesInMemory = 0;
		int totalStates = 0;
	public:
		Node* DepthLimitedSearch(ProblemLDFS*, Node*, int);
		void addInStack(vector<Node*>);
		void cleanStack();
		void outputSolution(Node*);
		void outputCounter();
};

#endif