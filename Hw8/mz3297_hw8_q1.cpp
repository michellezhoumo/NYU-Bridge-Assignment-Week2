#include <iostream>
using namespace std;

void printTriangle(int n);
void printOpositeTriangle(int n);
void printRuler(int n);

int main() {
    int size = 4;

    cout << "Section a. Print a right triangle" << endl;
    printTriangle(size);
    cout << endl << "Section b. Print two opposite right triangles" << endl;
    printOpositeTriangle(size);
    cout << endl << "Section c. Print ruler" << endl;
    printRuler(size);
    return 0;
}

//Section a. Print a Triangle
void printTriangle(int n){
    int i;
    if(n == 0) {
        return;
    }

    //return from base case up
    printTriangle(n-1);
    for(i = 1; i <= n; i++){
        cout << "*";
    }
    cout << endl;
}

//Section b. Print two opposite right triangles
void printOpositeTriangle(int n){
    int i;
    if(n == 0) {
        return;
    }

    for(i = 1; i <= n; i++){
        cout << "*";
    }
    cout << endl;
    printOpositeTriangle(n-1);
    for(i = 1; i <= n; i++){
        cout << "*";
    }
    cout << endl;
}

//Section c. Print Ruler
void printRuler(int n){
    int i;
    if(n == 0)
        return;
    printRuler(n-1);
    for(i = 1; i <=n; i++){
        cout << "-";
    }
    cout << endl;
    printRuler(n-1);
}