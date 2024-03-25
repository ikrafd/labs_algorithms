#ifndef BOARD_H  
#define BOARD_H
#include "Problem.h"
template <typename NodeType>
class BoardCreator
{
public:
    static NodeType* createStartBoard(int sizeBoard, Problem* problem) {
        vector<int> board(sizeBoard * sizeBoard, 0);
        srand(time(NULL));

        for (int i = 0; i < sizeBoard; ++i) {
            int pos = rand() % sizeBoard;
            board[i * sizeBoard + pos] = 1;
        }
        vector<pair<int, int>> position = problem->FindQueen(board);
        
        return new NodeType(board, position);
	}
};

template <>
inline NodeHeuristic* BoardCreator<NodeHeuristic>::createStartBoard(int sizeBoard, Problem* problem) {
    vector<int> board(sizeBoard * sizeBoard, 0);
    srand(time(NULL));

    for (int i = 0; i < sizeBoard; ++i) {
        int pos = rand() % sizeBoard;
        board[i * sizeBoard + pos] = 1;
    }

    vector<pair<int, int>> position = problem->FindQueen(board);

    // Special behavior for NodeHeuristic
    return new NodeHeuristic(board, position, problem->heuristics(board));
}

#endif

