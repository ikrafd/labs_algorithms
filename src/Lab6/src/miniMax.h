#include <utility>
#include <climits>
#include <algorithm>
#include <random>
class miniMax
{
	int board[25];
	int currentPlayer = 1;
	int figureInUse = 0;
	int pos[4] = { -1, -1, -1, -1 };

	int miniMaxWork(int depth, bool isMaximizingPlayer);
public:
	std::pair<int, int> move();
	miniMax();
	bool checkWin();
	void updateBoard(int old, int newPos);
	void setPlayer(int next);
	int getValueBoard(int cell);
	bool checkOver();
	int computerMove(int);
	int getPlayer();
	void clearBoard();
};

