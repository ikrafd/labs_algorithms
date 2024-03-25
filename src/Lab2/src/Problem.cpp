#include "Problem.h"

void Problem::setSizeBoard(int size)
{
    sizeBoard = size;
}

vector<pair<int, int>> Problem::FindQueen(vector<int>& valueState) {
    vector<pair<int, int>> positions;


    for (int i = 0; i < valueState.size(); i++) {
        if (valueState[i] == 1) {
            int row = i / sizeBoard;
            int column = i % sizeBoard;
            positions.emplace_back(row, column);
        }
    }

    return positions;
}


Problem::Problem(int size) : sizeBoard(size)
{
}

int Problem::heuristics(vector<int>& state) {
    int attackingPairs = 0;

    for (int i = 0; i < state.size(); ++i) {
        if (state[i] == 1) {
            int row = i / sizeBoard;
            int col = i % sizeBoard;

            std::vector<std::pair<int, int>> directions = {
                {0, 1}, {1, 0}, {0, -1}, {-1, 0},
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
            };

            for (auto& dir : directions) {
                int x = row, y = col;
                while (true) {
                    x += dir.first;
                    y += dir.second;

                    if (x < 0 || x >= sizeBoard || y < 0 || y >= sizeBoard) break;

                    if (state[x * sizeBoard + y] == 0) continue;

                    if (state[x * sizeBoard + y] == 1) {
                        attackingPairs++;
                        break;
                    }
                }
            }
        }
    }

    return attackingPairs / 2;
}

ProblemLDFS::ProblemLDFS(int size): Problem (size)
{
}

vector<Node*> ProblemLDFS::createChild(Node* parentNode) {

    vector <Node*> createdChilds;
    vector<int> parentState = parentNode->getState();
   
    vector<pair<int, int>> queenChildPositions;
    vector<int> childState;

    vector<pair<int, int>> directions = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };
    

    for (auto pos : parentNode->getQueenPosition()) {
        for (const auto& dir : directions) {
            int newRow = pos.first + dir.first;
            int newCol = pos.second + dir.second;
            
            if (newRow >= 0 && newRow < sizeBoard && newCol >= 0 && newCol < sizeBoard) {
                childState = parentState;
                int newIdx = newRow * sizeBoard + newCol;
                int oldIdx = pos.first * sizeBoard + pos.second;

                if (childState[newIdx] != 1) {
                    childState[oldIdx] = 0;
                    childState[newIdx] = 1;
                    statesChildCounter++;
                    if (parentStates.find(childState) == parentStates.end()) {
                        
                        queenChildPositions = FindQueen(childState);
                        Node* addressChild = new Node(childState, queenChildPositions,   parentNode->getLevelOfDeep() + 1, parentNode);
                        createdChilds.push_back(addressChild);
                    }
                }
            }
        }
    }
    return createdChilds;
}

void ProblemLDFS::addParentState(vector<int> newState)
{
    parentStates.insert(newState);
}

int ProblemLDFS::getCounter()
{
    return statesChildCounter;
}


ProblemHeuristic::ProblemHeuristic(int size) : Problem(size)
{
}

vector<NodeHeuristic*> ProblemHeuristic::createChild(NodeHeuristic* parentNode) {

    vector<NodeHeuristic*> childStates;
    vector<int> parentState = parentNode->getState();
    //int sizeBoard = startBoard.getSizeBoard();

    vector<pair<int, int>> queenChildPositions;
    vector<int> childState;

    vector<pair<int, int>> directions = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };

    for (auto pos : parentNode->getQueenPosition()) {
        for (const auto& dir : directions) {
            int newRow = pos.first + dir.first;
            int newCol = pos.second + dir.second;

            if (newRow >= 0 && newRow < sizeBoard && newCol >= 0 && newCol < sizeBoard) {
                childState = parentState;
                int newIdx = newRow * sizeBoard + newCol;
                int oldIdx = pos.first * sizeBoard + pos.second;

                if (childState[newIdx] != 1) {
                    childState[oldIdx] = 0;
                    childState[newIdx] = 1;
                    queenChildPositions = FindQueen(childState);

                    NodeHeuristic* addressChild = new NodeHeuristic(childState, queenChildPositions, heuristics(childState), parentNode, parentNode->getH() + 1);
                    childStates.push_back(addressChild);

                }
            }
        }
    }

    return childStates;
}