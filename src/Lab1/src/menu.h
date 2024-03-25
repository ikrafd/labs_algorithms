#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <cmath>
#include "createFile.h"
#include "algorithm.h"

using namespace std::chrono;
using namespace std;


class workWithFile {
    string fileNameWork = "A.bin";
    string fileNameStart = "start.bin";
    int start = 0;
    int numberOfOutput = 5;
    int factorGroupe = 5;
    int interval = 7;
    void outputChunk(ifstream&, int, int);
public:
    void outputFile(int);
    bool checkInput(string, int, int);
};

class menu {
    algorithm algorithms;
    clock_t start, end;
    double sec;
    int degree;
    const int lowerBound = 50;
    const int upperBound = 99999998;
    const int chooseRun = 1;
    const int chooseExit = 2;
    int sizeOfGroup;

    void inputNum();
    void sortFile();
    void runProgram();
    int numberCount = 0;
    workWithFile outFile;
    
public:
    void outputMenu();
};


#endif //TEST_FILE_H
