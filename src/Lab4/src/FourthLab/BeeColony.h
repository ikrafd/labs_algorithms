#ifndef BEECOLONY_H
#define BEECOLONY_H

#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <iostream>
#include "Graph.h"

using namespace std;
struct Bee {
    int vertex;  
    int nectar = 0;  
    bool isScout; 
};

class BeeColony {
private:
    Graph& graph;
    int beeCount;
    int scoutCount; 
    set<int> usedColors;
    int chromaticNumber;
    vector<Bee> bees;
    int countUseVertex = 0;

    void updateUsedColors();
    void moveBees();
    void calculateNectar(int valueIgnor);
    int findBestVertex();
    void assignColorToVertex(int vertexIndex);
    int selectColor(int vertex, vector<int>& neighborColors);
    vector<int> useVertices;
    

public:
    BeeColony(Graph& graph, int beeCount, int scoutCount);
    bool checkPainting();
    void solve(int maxIterations);
    bool isProperlyColored();
};
#endif
