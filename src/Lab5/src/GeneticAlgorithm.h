#ifndef GENETICALGORITHM_H  
#define GENETICALGORITHM_H 
#include <vector>
#include <random>
#include <algorithm>
#include <set>
#include "Graph.h"
#include <iostream>
using namespace std;
struct  Solution
{
	vector<int> value;
	int vertexCounter; 
};

class GeneticAlgorithm
{
	Graph& graph;
	vector<Solution> solutions;
	Solution child;
	int populationSize;
	int bestValue;
	set<pair<int, int>> edgesInSolution;
	vector <int> bestVertex;
	
	bool isVertexCover(Solution&);
	pair<int, int> findParent();
	void evenCross(pair<int, int> parents, Solution& child);
	void mutation(Solution& child);
	void deleteBad();
	void localImprovementOperator(Solution& initialSolution);
	float generate(int min, int max);
	void genratePopulation();

public:
	GeneticAlgorithm(Graph& graph, int sizePopulation);
	vector<Vertex> solve(int iteration);
};
#endif