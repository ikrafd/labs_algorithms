#include "BeeColony.h"


BeeColony::BeeColony(Graph& graph, int beeCount, int scoutCount) : graph(graph), beeCount(beeCount), scoutCount(scoutCount), chromaticNumber(0)
{
    bees.resize(beeCount);
    for (int i = 0; i < beeCount; ++i) {
        bees[i].isScout = (i < scoutCount);
    }
}

void BeeColony::solve(int maxIterations) {

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        if (countUseVertex >= graph.vertexCount) {
            calculateNectar(0);
        }
        else {
            calculateNectar(-1);
        }
        moveBees();
        updateUsedColors();
        if (!usedColors.empty()) {
            int currentChromaticNumber = *max_element(usedColors.begin(), usedColors.end());
            if (currentChromaticNumber < chromaticNumber || chromaticNumber == 0) {
                chromaticNumber = currentChromaticNumber;
            }
            if (iteration % 20 == 0) {

                cout << "Iteration:" << iteration << " The chromatic number: " << chromaticNumber << endl;
            }
        }
    }
}

void BeeColony::moveBees() {
    for (int beeIndex = 0; beeIndex < 3; beeIndex++) {
        int currentVertex = findBestVertex();
        vector<int> currentNeighbor = graph.getNeighbors(currentVertex);
        int neighborIndex = 0;
        for (neighborIndex; (neighborIndex < graph.vertices[currentVertex].neighbors.size()) && (neighborIndex < beeCount); ++neighborIndex) {
            if (!bees[neighborIndex].isScout) {
                assignColorToVertex(currentNeighbor[neighborIndex]);
            }
        }
        if (neighborIndex == graph.vertices[currentVertex].neighbors.size()) {
            graph.vertices[currentVertex].nectar = -1;
            countUseVertex++;
            assignColorToVertex(currentVertex);
        }
    }
}

void BeeColony::updateUsedColors()
{
    usedColors.clear();
    for (int i = 0; i < graph.vertexCount; ++i) {
        if (graph.vertices[i].color != -1) {
            usedColors.insert(graph.vertices[i].color);
        }
    }
};

int BeeColony::findBestVertex()
{
    int bestVertex = 0;
    int index = 0;
    for (int i = 0; i < graph.vertices.size(); i++) {
        if (graph.vertices[i].nectar > bestVertex) {
            bestVertex = graph.vertices[i].nectar;
            index = i;
        }
    }
    return index;
}

int BeeColony::selectColor(int vertex, vector<int>& neighborColors) {
    int availableColor = 0;
    sort(neighborColors.begin(), neighborColors.end());

    for (int neighborColor : neighborColors) {
        if (neighborColor == availableColor) {
            availableColor++;
        }
    }
    return availableColor;
}

void BeeColony::assignColorToVertex(int vertexIndex) {
    vector<int> neighborColors;

    for (int neighbor : graph.vertices[vertexIndex].neighbors) {
        if (neighbor >= 0 && neighbor < graph.vertexCount) {
            if (graph.vertices[neighbor].color != -1) {
                neighborColors.push_back(graph.vertices[neighbor].color);
            }
        }
    }

    int color = selectColor(vertexIndex, neighborColors);
    graph.vertices[vertexIndex].color = color;
    usedColors.insert(color);
}

void BeeColony::calculateNectar(int valueIgnor)
{
    random_device rd;
    mt19937 rng(rd());  
    
    uniform_int_distribution<int> distribution(0, graph.vertexCount-1);
    useVertices.clear();

    while (useVertices.size() < scoutCount) {
        int random_number = distribution(rng);
        if ((find(useVertices.begin(), useVertices.end(), random_number) == useVertices.end()) && (graph.vertices[random_number].nectar!=valueIgnor)) {
            useVertices.push_back(random_number);
        }
    }
    for (int num = 0; num < scoutCount; num++) {
        for (int i = 0; i < beeCount; i++) {
            if (bees[i].isScout) {
                graph.vertices[useVertices[num]].nectar = graph.vertices[num].degree;
            }
        }
    }
}

bool BeeColony::checkPainting()
{
    for (int i = 0; i < graph.vertexCount; i++) {
        if (graph.vertices[i].color == -1) {
            return false;
        }
    }
    return true;
}

bool BeeColony::isProperlyColored() {
    for (int i = 0; i < graph.vertexCount; i++) {
        int currentColor = graph.vertices[i].color;

        for (int neighbor : graph.vertices[i].neighbors) {
            if (graph.vertices[neighbor].color == currentColor) {
                return false;
            }
        }
    }
    return true; 
}
