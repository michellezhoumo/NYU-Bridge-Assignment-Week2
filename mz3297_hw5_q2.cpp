#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    cout <<"Section A Output: " << endl;
    printShiftedTriangle(3,4,'+');
    cout << endl << "Section B Output: " << endl;
    printPineTree(3, '+');
    return 0;
}

//section A. Function that prints the shifted triangle with the given symbol
void printShiftedTriangle(int n, int m, char symbol){
    int numOfSpace, numOfSymbol, spaceCount, symbolCount;
    char sym;
    for (numOfSpace = m + n - 1, numOfSymbol = 1; numOfSpace >= m, numOfSymbol <= (2 * n - 1); numOfSpace--, numOfSymbol += 2){
        for(spaceCount = 1; spaceCount <= numOfSpace; spaceCount ++){
            cout << " ";
        }
        for(symbolCount = 1; symbolCount <= numOfSymbol; symbolCount ++){
            cout << symbol;
        }
        cout << endl;
    }
}

//section B. Print a pine tree with given symbol

void printPineTree(int n, char symbol){
    int numOfLine, shift, countTriangle;
    for (countTriangle = 1, shift = n-1 ; countTriangle <= n, shift >= 0; countTriangle ++, shift--){
        numOfLine = countTriangle + 1;
        printShiftedTriangle(numOfLine, shift,symbol);
    }
}

