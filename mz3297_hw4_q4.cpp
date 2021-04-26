#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Section A. Read Input without stopping character" << endl;
    int lengthOfSeq;
    int seq, sumA, sumB, countA, countB;
    double geoMeanA, geoMeanB;
    bool indicator = false;

    cout << "Please enter the length of the sequence: ";
    cin >> lengthOfSeq;

    cout << "Please enter your sequence: " << endl;
    countA = 0;
    sumA = 0;
    while (countA < lengthOfSeq) {
        cin >> seq;
        sumA += seq;
        countA++;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    geoMeanA = pow(sumA, (double)1/(double)lengthOfSeq);
    cout << "The geometric mean is: " <<  geoMeanA << endl;
    cout << endl;

    cout << "Section B. Read Input with a stopping character" << endl;

    cout << "Please enter your sequence: " << endl;
    countB = 0;
    geoMeanB = 0;
    sumB = 0;

    while(indicator == false){
        cin >> seq;
        if (seq == -1){
            indicator = true;
        }
        else {
            sumB += seq;
            countB++;
        }
    }

    geoMeanB = pow(sumB, (double)1/(double)countB);
    cout << "The geometric mean is: " <<  geoMeanB << endl;
    cout << endl;


    return 0;
}
