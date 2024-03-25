#include "LDFS.h"
void LDFS::cleanStack()
{
    while (!stackNode.empty())
    {
        Node* currentNode = stackNode.top();
        stackNode.pop();
        delete currentNode;
    }
}

void LDFS::outputSolution(Node* result)
{
     if (result->getIsSolution() == true) {

         cout << "Solution found:" << endl;
         result->outputBoard();
         outputCounter();
     }      
     else {
         cout << "Solution don`t found" << endl;
         outputCounter();
     }   
       
}

void LDFS::outputCounter()
{
    cout << "Iteration: " << iterationCount << endl;
    cout << "DeadEnd: " << deadEndCount << endl;
    cout << "Total: " << totalStates << endl;
    cout << "In memory: " << statesInMemory << endl;
}


Node* LDFS::DepthLimitedSearch(ProblemLDFS* problem, Node* start, int limit) {
    stackNode.push(start);
    totalStates++;
    statesInMemory++;

    while (!stackNode.empty()) {
        iterationCount++;
        Node* currentNode = stackNode.top();

        if (problem->heuristics(currentNode->getState()) == 0) {
            currentNode->setIsSolution(true);
            solutionNode = currentNode;
            return currentNode;
        }

        if ((currentNode->getHaveChild() == false) && (currentNode->getLevelOfDeep() < limit)) {
            vector <Node*> child = problem->createChild(currentNode);
            totalStates += problem->getCounter();
            statesInMemory += problem->getCounter();
            addInStack(child);
            problem->addParentState(currentNode->getState());
            currentNode->setHaveChild(true);
        }
        else if (stackNode.size() > 1) {
            stackNode.pop();
            deadEndCount++;
            statesInMemory--;
            delete currentNode;

        }
        else if (stackNode.size() == 1) {
            stackNode.pop();
        }
    }

    return start;
}

void LDFS::addInStack(vector<Node*> child)
{
    for (auto it = child.rbegin(); it != child.rend(); ++it) {
        stackNode.push(*it);
    }
}
