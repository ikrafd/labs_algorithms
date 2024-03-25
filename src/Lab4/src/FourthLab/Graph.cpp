#include "Graph.h"

Graph::Graph(int numVertices, int maxDegree) : vertexCount(numVertices)
{
    vertices.resize(numVertices);

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < numVertices; ++i) {
        vertices[i].color = -1;
        vertices[i].degree = 0;

        std::uniform_int_distribution<> neighborsCountDist(1, maxDegree);
        int neighborsCount = neighborsCountDist(gen);

        std::uniform_int_distribution<> dis(0, numVertices - 1);

        while (vertices[i].neighbors.size() < neighborsCount) {
            int neighbor = dis(gen);

            if (neighbor != i &&
                std::find(vertices[i].neighbors.begin(), vertices[i].neighbors.end(), neighbor) == vertices[i].neighbors.end() &&
                vertices[neighbor].neighbors.size() < maxDegree) {
                vertices[i].neighbors.push_back(neighbor);
                vertices[neighbor].neighbors.push_back(i);

                vertices[i].degree++;
                vertices[neighbor].degree++;
            }
        }
    }
}
vector<int> Graph::getNeighbors(int vertexIndex)
{
    Vertex& currentVertex = vertices[vertexIndex];
    vector<int> neighborsVertex;
    for (int neighborIndex : currentVertex.neighbors) {
        neighborsVertex.push_back(neighborIndex);
    }
    return neighborsVertex;
}
;
