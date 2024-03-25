#include "algorithm.h"

void algorithm::writeInFile(ofstream& write, ifstream& read, int sizeOfGroup) {
    int t;
    for (int i = 0; i != sizeOfGroup && (read >> t); i++) {
        write << t << " ";
    }
}
void algorithm::writeInBC(int sizeOfGroup) {

    ifstream aRead(mainFile, ios::binary);
    ofstream bWrite(firstHelpFile, ios::binary), cWrite(secondHelpFile, ios::binary);
    
    if (sizeOfGroup <= 0) {
        throw invalid_argument("sizeOfGroup can`t be less then 0");
    }

    while (aRead.peek() != EOF) {
        writeInFile(bWrite, aRead, sizeOfGroup);
        writeInFile(cWrite, aRead, sizeOfGroup); 
    }

    aRead.close();
    bWrite.close();
    cWrite.close();

}

void algorithm::mergeInA(int sizeOfGroup) {

    ofstream aWrite(mainFile, ios::binary);
    ifstream bRead(firstHelpFile, ios::binary), cRead(secondHelpFile, ios::binary);
    int numberC, numberB;

    if (sizeOfGroup <= 0) {
        throw invalid_argument("sizeOfGroup can`t be less then 0");
    }

    bRead >> numberB;
    cRead >> numberC;
    while (!bRead.eof() && !cRead.eof()) {
        while (b < sizeOfGroup && c < sizeOfGroup && !cRead.eof()) {
            if (numberB < numberC) {
                aWrite << numberB << " ";
                bRead >> numberB;
                b++;
            }
            else if (numberB > numberC) {
                aWrite << numberC << " ";
                cRead >> numberC;
                c++;
            }
            else {
                aWrite << numberB << " " << numberC << " ";
                bRead >> numberB;
                cRead >> numberC;
                b++;
                c++;
            }
        }
        while (b != sizeOfGroup && !cRead.eof()) {
            aWrite << numberB << " ";
            bRead >> numberB;
            b++;
        }
        while (c != sizeOfGroup && !cRead.eof()) {
            aWrite << numberC << " ";
            cRead >> numberC;
            c++;
        }
        c = b = 0;
    }
    while (!bRead.eof()) {
        aWrite << numberB << " ";
        bRead >> numberB;
    }

    aWrite.close();
    bRead.close();
    cRead.close();

}