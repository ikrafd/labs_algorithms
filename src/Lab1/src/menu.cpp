#include "menu.h"


void workWithFile::outputChunk(ifstream& File, int start, int count) {
    int counter = 0;
    int temp;
    while (counter < start && File >> temp) {
        counter++;
    }

    while (counter < start + count && File >> temp) {
        cout << temp;
        if (counter < start + count - 1) {
            cout << " ";
        }
        counter++;
    }
}


void workWithFile::outputFile(int sizeOfGroup) {

    ifstream file(fileNameWork, ios::binary);
        cout << "file:";
        outputChunk(file, start, numberOfOutput);
        cout << "... ";
        outputChunk(file, sizeOfGroup * factorGroupe - interval, numberOfOutput);
        cout << "... ";
        outputChunk(file, sizeOfGroup * factorGroupe - interval, numberOfOutput);
        cout << endl;
    
    file.close();
}

bool workWithFile::checkInput(string input, int start, int end) {
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


void menu::inputNum() {
    string number;
    int count;
    bool rezCheck;
    do {
        cout << "Input how many intenger in file " << lowerBound<<" - "<< upperBound<<" ";
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        rezCheck = outFile.checkInput(number, lowerBound, upperBound);
    } while (!rezCheck);
    count = stoi(number);
    numberCount = count;
}

void menu::outputMenu() {
    string input;
    do {
        cout << "MENU:\n 1 - start generate and sort\n 2 - out from program" << endl;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (outFile.checkInput(input,chooseRun, chooseExit)) {
            if (input[0] == '1') {
                runProgram();
            }
        }
    } while (input[0] != '2');
}

void menu::runProgram() {
    inputNum();
    createFile newFile(numberCount);
    degree = newFile.findDegree();
    newFile.generateFile(degree);
    sizeOfGroup = pow(2, degree);
    outFile.outputFile(sizeOfGroup);
    sortFile();
    outFile.outputFile(sizeOfGroup);
    cout << "Done " << sec << " seconds" << endl;
}

void menu::sortFile() {
    start = clock();
    int current_degree = 0;
    do {
        current_degree = pow(2, degree);
        algorithms.writeInBC(current_degree);
        algorithms.mergeInA(current_degree);
        degree++;
    } while (numberCount / 2 >= current_degree);
    end = clock();
    sec = ((double)(end - start) / CLOCKS_PER_SEC);
}