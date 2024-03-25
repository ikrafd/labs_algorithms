#ifndef MENU_H  
#define MENU_H
#include <string>
#include <iostream>
#include "RBFS.h"
#include "LDFS.h"
#include "BoardCreator.h"
using namespace std;
class Menu
{
	int chooseLDFS = 1;
	int chooseRBFS = 2;
	int chooseExit = 3;
	int sizeBoard = 8;
	
	bool checkInput(string input, int start, int end);
	void runLDFS();
	void runRBFS();
public:
	void outputMenu();
};
#endif

