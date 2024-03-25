#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
struct Vertex {
    int degree;
    int color; 
    int nectar;
    vector<int> neighbors; 
};

class Graph {
private:
    vector<Vertex> vertices; 
    int vertexCount;
    vector<int> colors; 
public:
    Graph(int numVertices, int maxDegree);
    friend class BeeColony;
    vector<int> getNeighbors(int vertexIndex);
};
#endif