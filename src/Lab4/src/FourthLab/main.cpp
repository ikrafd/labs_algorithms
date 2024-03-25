#include "BeeColony.h"
int main() {
    char choice;

    do {
        Graph graph(150, 30);
        BeeColony colony(graph, 35, 3);
        colony.solve(1000);

        if (colony.isProperlyColored()) {
            cout << "Color full" << endl;
        }
        else {
            cout << "Not all" << endl;
        }
        cout << "Do you want to run the program again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}