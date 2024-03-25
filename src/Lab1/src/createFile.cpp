#include "createFile.h"

createFile::createFile(int num) {
    numberCount = num;
}

void createFile::generateFile(int degree) {
    ofstream aWrite(mainFile, ios::binary | ios::trunc);
    int num = 0;
    int sizeGroup = pow(2, degree);

    cout << "Start generate" << endl;

    for (int i = 0; i < numberOfPieces; i++) {
        int n = 0;
        group.clear();
        while (n < sizeGroup) {
            num = rand() % rangeGenerate;
            group.push_back(num);
            n++;
        }
        sort(group.begin(), group.end());
        for (int nums : group) {
            aWrite << nums << " ";
        }
    }
    cout << "Start file was create" << endl;

    aWrite.close();
}

int createFile::findDegree() {
    int n = 0;
    while (pow(2, n) < numberCount) {
        n++;
    }
    n -= 5;

    if (n < 0) {
        n=0;
    }
    return n;
}