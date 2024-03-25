#include "RBFS.h"

void RBFS::sortChild(vector<NodeHeuristic*>* successors)
{
    sort(successors->begin(), successors->end(), [](NodeHeuristic* a, NodeHeuristic* b) {
        return a->getBestF() < b->getBestF();
        });
}


int RBFS::RecursiveBestFirstSearch(NodeHeuristic* node, ProblemHeuristic* problem, int B)
{
    iterationCount++;
    bool findBetter = false;
    vector<NodeHeuristic*> successors;
    if (problem->heuristics(node->getState()) == 0) {
        if (!successors.empty()) {
            for (auto* ptr : successors) {
                delete ptr;
            }
        }
        solutionFound = true;
        solutionNode = node;
        return node->getBestF();
    }
    successors = problem->createChild(node);
    allNode.insert(allNode.end(), successors.begin(), successors.end());
    totalStates += successors.size();
    NodeHeuristic* best = successors[0];
    if (successors.empty()){
        deadEndCount++;
        return INFINITY;
    } 
    for (auto child : successors) {
        if (node->getCurrentF() < node->getBestF()) {
            child->setBestF(max(node->getBestF(), child->getCurrentF()));
            findBetter = true;
        }
        else {
            child->setBestF(child->getCurrentF());
        }
    }
    if (findBetter) statesInMemory -= successors.size() - 2;
    statesInMemory += successors.size();
    sortChild(&successors);

    while (successors[0]->getBestF() <= B && successors[0]->getBestF() < INFINITY && !solutionFound) {
        successors[0]->setBestF( RecursiveBestFirstSearch(successors[0], problem, min(B, successors[1]->getBestF())));
        if (!solutionFound) {
            sortChild(&successors);
        }
        else {
            return successors[0]->getBestF();
        }
    }

    return successors[0]->getBestF();
}

void RBFS::outputSolution()
{
    if (solutionFound) {
        cout << "Solution found:" << endl;
        solutionNode->outputBoard();
        outputCounter();
    }
    else {
        cout << "Solution don`t found:" << endl;
        outputCounter();
    }
}

void RBFS::cleanNode()
{
    for (NodeHeuristic* node : allNode) {
        delete node;
    }
}

bool RBFS::getSolutionFound()
{
    return solutionFound;
}

void RBFS::outputCounter()
{
    cout << "Iteration: " << iterationCount << endl;
    cout << "DeadEnd: " << deadEndCount << endl;
    cout << "Total: " << totalStates << endl;
    cout << "In memory: " << statesInMemory << endl;
}
