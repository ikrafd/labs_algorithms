#ifndef NODE_H  
#define NODE_H

#include <vector>
#include <iostream>

using namespace std;
class Node
{	
	int levelOfDeep;
	Node* parent;
	bool haveChild;
protected:
	vector<int> state;
	int sizeBoard;
	bool isSolution;
	vector<pair<int, int>> queenPosition;
	
public:
	Node();
	Node(vector<int>, vector<pair<int,int>>, int = 0, Node* = nullptr);

	void setIsSolution(bool);
	void setState(vector<int>);
	void setHaveChild(bool);
	void setQueenPosition(vector<pair<int, int>>&);

	vector<int>& getState();
	bool getIsSolution();
	Node* getParent();
	int getLevelOfDeep();
	bool getHaveChild();
	vector<pair<int, int>>& getQueenPosition();
	int getSizeBoard();
	
	void outputBoard();

};

class NodeHeuristic : public Node {
	int g;
	int h;
	int currentF;
	int bestF;
public:
	
	NodeHeuristic(vector<int>, vector<pair<int, int>>,int=0, Node* = nullptr, int = 0);
	NodeHeuristic();
	int getH();
	int getG();
	int getCurrentF();
	int getBestF();

	void setCurrentF(int);
	void setBestF(int);
	void setG(int);
};
#endif 