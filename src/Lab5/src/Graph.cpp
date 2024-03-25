#include "Graph.h"
vector<int> Graph::findBestVertex()
{
    vector<int> bestVertex;
    int maxValue = 0;
    for (int i = 0; i < vertexCount; i++) {
        if (vertices[i].degree > maxValue) {
            maxValue = vertices[i].degree;
        }
    }
    for (int i = 0; i < vertexCount; i++) {
        if (vertices[i].degree == maxValue) {
            bestVertex.push_back(i);
        }
    }

    return bestVertex;
}
Graph::Graph(int numVertices, int minDegree, int maxDegree) : vertexCount(numVertices)
{
    vertices.resize(numVertices);

    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < numVertices; ++i) {
        vertices[i].degree = 0;

        uniform_int_distribution<> neighborsCountDist(minDegree, maxDegree);
        int neighborsCount = neighborsCountDist(gen);

        uniform_int_distribution<> dis(0, numVertices - 1);

        while (vertices[i].neighbors.size() < neighborsCount) {
            int neighbor = dis(gen);

            if (neighbor != i &&
                find(vertices[i].neighbors.begin(), vertices[i].neighbors.end(), neighbor) == vertices[i].neighbors.end() &&
                vertices[neighbor].neighbors.size() < maxDegree) {
                vertices[i].neighbors.push_back(neighbor);
                vertices[neighbor].neighbors.push_back(i);
                edges.emplace_back(i, neighbor);
                vertices[i].edgesVertex.emplace_back(i, neighbor);
                vertices[neighbor].edgesVertex.emplace_back(i, neighbor);
            }
        }
    }
    for (int i = 0; i < numVertices; ++i) {
        vertices[i].degree = vertices[i].neighbors.size();
    }
}