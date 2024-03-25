#ifndef GRAPH_H  
#define GRAPH_H
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
struct Vertex {
    int degree;
    vector<int> neighbors;
    vector<pair<int, int>> edgesVertex;
};

class Graph {
private:
    vector<Vertex> vertices;
    int vertexCount;
    vector<pair<int, int>> edges;
    vector<int> findBestVertex();
public:
    Graph(int numVertices, int minDegree, int maxDegree);
    
    vector<int> getNeighbors(int vertexIndex);
    friend class GeneticAlgorithm;
};
#endif
