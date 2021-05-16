#include <iostream>
using namespace std;

void outputPosNum(int* arr, int arrSize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);


int main() {
    int arSize = 6, posArSize1,i;;
    int ar[6] = {3, -1, -3, 0, 6, 4};

    cout << "Input Array = {3, -1, -3, 0, 6, 4}" << endl << endl;

    int * posAr;
    posAr = getPosNums1(ar, arSize, posArSize1);
    cout << "Section a. Output: ";
    outputPosNum(posAr, posArSize1);
    delete[] posAr;

    int posArSize2 = 0;
    posAr = getPosNums2(ar, arSize, &posArSize2);
    cout << "Section b. Output: ";
    outputPosNum(posAr, posArSize2);
    delete[] posAr;

    int posArSize3;
    posAr = new int[posArSize3];
    getPosNums3(ar, arSize, posAr, posArSize3);
    cout << "Section c. Output: ";
    outputPosNum(posAr, posArSize3);
    delete[] posAr;

    int posArSize4 = 0;
    posAr = new int[posArSize3];
    getPosNums4(ar, arSize, &posAr, &posArSize4);
    cout << "Section d. Output: ";
    outputPosNum(posAr, posArSize4);
    delete[] posAr;
    return 0;
}

void outputPosNum(int* arr, int arrSize){
    cout << "{";
    for(int i = 0; i < arrSize; i++)
        if(i == arrSize - 1)
            cout << arr[i];
        else
            cout << arr[i] << ",";
    cout << "}" << endl;
}


//Part a. Pass arrSize as a reference, return a heap dynamic array of int
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int i,j=0;
    int posArrSize = 0;
    int * posArr = new int[posArrSize];
    for (i = 0; i < arrSize; i++){
        if (arr[i] > 0) {
            posArrSize++;
            posArr[j] = arr[i];
            j++;
        }
    }
    outPosArrSize = posArrSize;
    return posArr;
}

//Part b. pass a pointer that is the address of PosArrSize value
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int i,j=0;
    //take out value at that address
    int posArrSize = *outPosArrSizePtr;
    int * posArr = new int[posArrSize];
    for (i = 0; i < arrSize; i++){
        if (arr[i] > 0) {
            (posArrSize)++;
            posArr[j] = arr[i];
            j++;
        }
    }
    //put value back into pointer
    *outPosArrSizePtr = posArrSize;
    return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int posArrSize = 0,j = 0;
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0) {
        (posArrSize)++;
        *(outPosArr + j) = arr[i];
        j++;
    }
}
    outPosArrSize = posArrSize;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int posArrSize = 0,j = 0;
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0) {
            (posArrSize)++;
            *(*outPosArrPtr + j) = arr[i];
            j++;
        }
    }
    * outPosArrSizePtr = posArrSize;
}