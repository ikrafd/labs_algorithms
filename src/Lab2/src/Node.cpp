#include "Node.h"

Node::Node(): isSolution(false), haveChild(false), state(0), parent(nullptr), levelOfDeep(0), sizeBoard(8)
{
}

Node::Node(vector<int> valueState, vector<pair<int, int>> queenPositions, int level, Node* parentNode) : isSolution(false), haveChild(false) , sizeBoard(8)
{
    parent = parentNode;
    state = valueState;
    levelOfDeep = level;
    queenPosition = queenPositions;
}


vector<int>& Node::getState()
{
    return state;
}

void Node::setIsSolution(bool newValue)
{
    isSolution = newValue;
}

bool Node::getIsSolution()
{
    return isSolution;
}

void Node::outputBoard() {
   
    for (int i = 0; i < state.size(); i++) {
        if (i % sizeBoard == 0 && i != 0) {
            cout << endl;
        }

        if (state[i] == 1) {
            cout << "X ";
        }
        else {
            cout << "- ";
        }
    }
    cout << "\n\n";
}


void Node::setState(vector<int> newState)
{
    state = newState;
}

void Node::setHaveChild(bool newValue)
{
    haveChild = newValue;
}

void Node::setQueenPosition(vector<pair<int, int>>& newPosition)
{
    queenPosition = newPosition;
}

Node* Node::getParent() {
    return parent;
}

int Node::getLevelOfDeep()
{
    return levelOfDeep;
}

bool Node::getHaveChild()
{
    return haveChild;
}

vector<pair<int, int>>& Node::getQueenPosition()
{
    return queenPosition;
}

int Node::getSizeBoard()
{
    return sizeBoard;
}

NodeHeuristic::NodeHeuristic(vector<int> valueState, vector<pair<int, int>> queenPositions, int gValue, Node* parentNode, int hValue): Node (valueState, queenPositions,0, parentNode), h(hValue), g(gValue)
{
    currentF = hValue + gValue;
    bestF = currentF;

}

int NodeHeuristic::getH()
{
    return h;
}

int NodeHeuristic::getG()
{
    return g;
}



int NodeHeuristic::getCurrentF()
{
    return currentF;
}

int NodeHeuristic::getBestF()
{
    return bestF;
}

NodeHeuristic::NodeHeuristic() : g(0), currentF(0), h(0), bestF(0)
{
}

void NodeHeuristic::setCurrentF(int newF)
{
    currentF = newF;
}

void NodeHeuristic::setBestF(int newBest)
{
    bestF = newBest;
}

void NodeHeuristic::setG(int newG)
{
    g = newG;
}
