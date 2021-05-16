#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int aSize = 6, missingNumArrSize;
    int a[6] = {3,1,3,0,6,4};
    int* missingNumArr;
    missingNumArr = findMissing(a, aSize, missingNumArrSize);

    cout << "Missing Numbers are: [";
    for(int i = 0; i < missingNumArrSize; i++){
        if(i == missingNumArrSize - 1)
            cout << missingNumArr[i];
        else
            cout << missingNumArr[i] << ",";
    }
    cout << "]" << endl;
    cout << "There are " << missingNumArrSize << " missing numbers." << endl;
    delete[] missingNumArr;
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    int * ar = new int[n]{0};
    int missingNumSize=0;
    int * missingNum = new int[missingNumSize];
    for (int i = 0; i < n; i++){
        ar[arr[i]] ++;
    }
    for(int i = 0; i < n; i++){
        if(ar[i] == 0) {
            missingNum[missingNumSize] = i;
            missingNumSize++;
        }
    }

    resArrSize = missingNumSize;
    delete[] ar;

    return missingNum;
}