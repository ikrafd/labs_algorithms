#include "miniMax.h"

miniMax::miniMax()
{
    for (int i = 0; i < 25; i++) {
        board[i] = 0;
    }
};

bool miniMax::checkWin()
{
    for (int col = 0; col < 5; col++) {
        for (int row = 0; row < 2; row++) {
            int count = 0;
            for (int i = 0; i < 4; i++) {
                if (board[col + row * 5 + i] == currentPlayer) {
                    count++;
                }
            }
            if (count == 4) {
                return true;
            }
        }
    }

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 2; col++) {
            int count = 0;
            for (int i = 0; i < 4; i++) {
                if (board[col + row * 5 + i * 5] == currentPlayer) {
                    count++;
                }
            }
            if (count == 4) {
                return true;
            }
        }
    }

    for (int diag = 0; diag < 2; diag++) {
        for (int start = 0; start < 21; start += 5) {
            int count = 0;
            for (int i = 0; i < 4; i++) {
                if (board[start + diag * 4 + i * 6] == currentPlayer) {
                    count++;
                }
            }
            if (count == 4) {
                return true;
            }
        }
    }

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int count = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (board[col + row * 5 + i + j * 5] == currentPlayer) {
                        count++;
                    }
                }
            }
            if (count == 4) {
                return true;
            }
        }
    }

    return false;
}

void miniMax::updateBoard(int old, int newPos)
{
    int i = 0;
    if (old-1 > -1) {
        board[old-1] = 0;
    }
    if (newPos - 1 > -1) {
        board[newPos - 1] = currentPlayer;
    }
    
}
int miniMax::getPlayer()
{
    return currentPlayer;
}

void miniMax::clearBoard()
{
    for (int i = 0; i < 25; i++) {
        board[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
        pos[i] = -1;
    }

    currentPlayer = 1;
    figureInUse = 0;
}

std::pair<int, int> miniMax::move() {
    if (figureInUse < 4) {
        figureInUse++;
        return { computerMove(figureInUse), figureInUse};
    }
    else {
        int selectedFigure = std::rand() % 4;
        board[pos[selectedFigure-1]] = 0;
        return {computerMove(selectedFigure), selectedFigure };
    }
    
}
 int miniMax::computerMove(int position)
{
    int bestMove = -1;
    int bestScore = INT_MIN;;
    int depth = 3;

    for (int i = 0; i < 25; i++) {
        if (board[i] == 0) {
            board[i] = 2; 
            int moveScore = miniMaxWork(depth - 1, true);
            board[i] = 0;

            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    pos[position-1] = bestMove;
    board[bestMove] = 2;
    return bestMove;
}

int miniMax::miniMaxWork (int depth, bool isMaximizingPlayer) {
    int score = checkWin();

    if (score != 0 || depth == 0) {
        return score;
    }

    if (isMaximizingPlayer) {
        int bestScore = INT_MIN;

        for (int i = 0; i < 25; i++) {
            if (board[i] == 0) {
                
                board[i] = 2;
                int childScore = miniMaxWork(depth - 1, false);
                bestScore = std::max(bestScore, childScore);
              
                board[i] = 0;
            }
        }

        return bestScore;
    }
    else {
        int bestScore = INT_MAX;

        for (int i = 0; i < 25; i++) {
            if (board[i] == 0) {
                board[i] = 2;
                int childScore = miniMaxWork(depth - 1, true);
                bestScore = std::min(bestScore, childScore);
                board[i] = 0;
            }
        }

        return bestScore;
    }
}

void miniMax::setPlayer(int next)
{
    currentPlayer = next;
}

int miniMax::getValueBoard(int cell)
{
    return board[cell];
}

bool miniMax::checkOver()
{
    int cur = currentPlayer;
    if (checkWin()) {
        return true;
    }
    else {
        if (cur == 1) {
            currentPlayer = 2;
        }
        else {
            currentPlayer = 1;
        }

        if (checkWin()) {
            return true;
        }
        else {
            currentPlayer = cur;
            return false;
        }
    }
}
