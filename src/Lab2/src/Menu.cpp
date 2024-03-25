#include "Menu.h"


void Menu::outputMenu() {
    string input;
    do {
        cout << "MENU:\n 1 - choose LDFS\n 2 - choose RBFS\n 3 - out from program" << endl;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (checkInput(input, chooseLDFS, chooseExit)) {
            if (input[0] == '1') {
                runLDFS();
            }
            if (input[0] == '2') {
                runRBFS();
            }
        }
    } while (input[0] != '3');
}

bool Menu::checkInput(string input, int start, int end) {
    int num;
    try {
        if (input[0] == '0') {
            cout << "Invalid input, you can`t input 0" << endl;
            return false;
        }

        num = stoi(input);

        double decimalPart = stod(input);
        if (fmod(decimalPart, 1.0) != 0.0) {
            cout << "Invalid input, only integers are allowed." << endl;
            return false;
        }

        if (num < start || num > end) {
            cout << "Invalid input, input " << start << " - " << end << endl;
            return false;
        }
        return true;
    }
    catch (invalid_argument&) {
        cout << "Invalid input, not a valid integer." << endl;
        return false;
    }
}

void Menu::runLDFS()
{
    LDFS firstAlgoritm;
    ProblemLDFS problem(sizeBoard);

    Node* startNode = BoardCreator<Node>::createStartBoard(sizeBoard, &problem);
    cout << "Generate state: " << endl;
    startNode->outputBoard();

    int level = 7;
    cout << "Start LDFS algoritm... \n" << endl;
    Node* result = firstAlgoritm.DepthLimitedSearch(&problem, startNode, level);
    firstAlgoritm.outputSolution(result);
    firstAlgoritm.cleanStack();
}

void Menu::runRBFS()
{
    RBFS secondAlgoritm;
    ProblemHeuristic problem(sizeBoard);
    NodeHeuristic* startNode = BoardCreator<NodeHeuristic>::createStartBoard(sizeBoard, &problem);
    cout << "Generate state: " << endl;
    startNode->outputBoard();

    cout << "Start RBSF algoritm... \n" << endl;
    secondAlgoritm.RecursiveBestFirstSearch(startNode, &problem, 100);
    secondAlgoritm.outputSolution();

    secondAlgoritm.cleanNode();

    delete startNode;
}