#ifndef ALGORITHM_H 
#define ALGORITHM_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class algorithm {
   int b = 0;
   int c = 0;
   string mainFile = "A.bin";
   string firstHelpFile = "B.bin";
   string secondHelpFile = "C.bin";

   void writeInFile(ofstream&, ifstream&, int);
public:
    void mergeInA(int);
    void writeInBC(int);
};

#endif