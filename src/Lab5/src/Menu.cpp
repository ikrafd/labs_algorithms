#include "Menu.h"



void Menu::runProgram(int numVertices, int minDegree, int maxDegree, int sizePopulation, int iteration)
{
    char choice;

    do {
        Graph graph(numVertices, minDegree, maxDegree);
        GeneticAlgorithm algo(graph, sizePopulation);
        if (!algo.solve(iteration).empty()) {
            cout << "Solution was found" << endl;
        }
        else {
            cout << "Solution wasn`t found" << endl;
        }
        cout << "Do you want to run the program again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}
