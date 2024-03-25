#ifndef CREATEFILE_H 
#define CREATEFILE_H 

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>

using namespace std;

class createFile {
    vector<int> group;
    int numberCount;
    string mainFile = "A.bin";
    const int rangeGenerate = 20000;
    const int numberOfPieces = 10;
public:
    void generateFile(int);
    int findDegree();
    createFile(int);
};

#endif