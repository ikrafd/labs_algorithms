#include "GeneticAlgorithm.h"


GeneticAlgorithm::GeneticAlgorithm(Graph& graphValue, int sizePopulation) : graph(graphValue), populationSize(sizePopulation), bestValue(graph.edges.size())
{
}

vector<Vertex> GeneticAlgorithm::solve(int iteration)
{
    if (iteration == 0) {
        return vector<Vertex>();
    }
    genratePopulation();
    bestVertex = graph.findBestVertex();
    pair<int, int> parent;
    for (int i = 0; i < iteration; i++) {
        
        parent = findParent();
        Solution newChild;
        evenCross(parent, newChild);

        for (int j = 0; j < 3; j++) {
            child = newChild;
            mutation(newChild);

            if (!isVertexCover(newChild)) {
                newChild = child;
            }
            localImprovementOperator(newChild);
            localImprovementOperator(newChild);
            solutions.push_back(newChild);
            deleteBad();
        }

        if (i % 20 == 0) {
            cout <<"Iteration:"<<i << " Num of vertex: " << bestValue << endl;
        }
    }
    cout << "Iteration:" << iteration << " Num of vertex: " << bestValue << endl;

    vector<Vertex> solutionVector;
    int bestSolutionIndex = findParent().first;
    
    for (int i = 0; i < solutions[bestSolutionIndex].value.size();i++) {
        if (solutions[bestSolutionIndex].value[i] == 1) {
            solutionVector.push_back(graph.vertices[i]);
        }
    }
    return solutionVector;
}

float GeneticAlgorithm::generate(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void GeneticAlgorithm::genratePopulation()
{
    vector<Solution> initialPopulation;

    while (initialPopulation.size() < populationSize) {
        Solution solution;
        int counter = 0;
        for (int j = 0; j < graph.vertexCount; ++j) {
            if (j < graph.vertexCount - generate(0,7)) {
                solution.value.push_back(1); 
                counter++;
            }
            else {
                solution.value.push_back(0); 
            }
        }

        random_shuffle(solution.value.begin(), solution.value.end());

        if (isVertexCover(solution)) {
            solution.vertexCounter = counter;
            initialPopulation.push_back(solution);

        }
    }
    solutions = initialPopulation;
}

bool GeneticAlgorithm::isVertexCover(Solution& sol)
{
    edgesInSolution.clear();

    for (int i = 0; i < sol.value.size(); i++) {
        if (sol.value[i] == 0) {
            continue;
        }

        for (const auto& edge : graph.vertices[i].edgesVertex) {
            edgesInSolution.insert(edge);
        }
    }
    if (edgesInSolution.size() == graph.edges.size()) {
        return true;
    }
    else {
        return false;
    }
}


pair<int, int> GeneticAlgorithm::findParent()
{
    int bestParent = 0;
    int secondParent = 0;
    for (int i = 0; i < solutions.size(); i++) {
        if (solutions[i].vertexCounter <= bestValue) {
            bestValue = solutions[i].vertexCounter;
            bestParent = i;
        }
    }
    do {
        secondParent = generate(0, solutions.size() - 1);
    } while (secondParent == bestParent);

    return { bestParent, secondParent};
}

void GeneticAlgorithm::evenCross(pair<int, int> parents, Solution& child) {
 
    vector <int> parentA = solutions[parents.first].value;
    vector <int> parentB = solutions[parents.second].value;
    
    int num = 0;
    child.value.clear();
    for (int i = 0; i < solutions[parents.first].value.size(); i++) {

        double randomValue = generate(0.1, 1.0);

        if (randomValue < 0.2) {
            child.value.push_back(parentA[i]);
            if (parentA[i] == 1) {
                num++;
            }
        }
        else {
            child.value.push_back(parentB[i]);
            if (parentB[i] == 1) {
                num++;
            }
        }
    }
    child.vertexCounter = num;
    
}

void GeneticAlgorithm::mutation(Solution& child) {
    
    vector<int> mutatedSolution = child.value;
    for (int i = 0; i < 3; i++) {
        int firstValue = generate(0, child.value.size()-1);
        int secondValue = generate(0, child.value.size()-1);
        int x = child.value[firstValue];
        child.value[firstValue] = child.value[secondValue];
        child.value[secondValue] = x;
    }
}

void GeneticAlgorithm::deleteBad()
{
    int badValue = 0;
    int badParent = 0;
    for (int i = 0; i < solutions.size(); i++) {
        if (solutions[i].vertexCounter > badValue) {
            badValue = solutions[i].vertexCounter;
            badParent = i;
        }
    }
    solutions.erase(solutions.begin() + badParent);
    
}


void GeneticAlgorithm::localImprovementOperator(Solution& initialSolution) {
  
    int randomIndex = generate(0, bestVertex.size() - 1);

    int index = bestVertex[randomIndex];
    Solution currentSolution = initialSolution;
  
    if (currentSolution.value[index] == 0) {
        currentSolution.value[index] = 1;
        currentSolution.vertexCounter++;
    }

    if (isVertexCover(currentSolution)) {
        initialSolution = currentSolution;
       
    }
}

