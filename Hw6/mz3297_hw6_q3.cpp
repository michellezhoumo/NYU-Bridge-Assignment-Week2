#include <iostream>
#include <string>
using namespace std;
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void  splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}
void printArray(int arr[], int arrSize){
    int i;

    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize){
    int i,j,temp;
    for (i = 0, j = arrSize-1; i < arrSize/2; i++, j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

//Need to reduce runtime, currently O(n^2)
void removeOdd(int arr[], int& arrSize){
    int i,j,temp,countEven;
    countEven = 0;
    i = 0;
    j = i+1;
    while(i < arrSize) {

        //Case breakdown:
        // 1. a[i] is odd, find the first a[j] that is even, swap a[i],a[j], no even a[j], then return empty array;
        // 2. a[i] is even, shift i and j both to the right, and increment even number count;
        //Loop-End fix:
        // break before j becomes index out of range

        if(arr[i] % 2 == 1) {
            if (arr[j] % 2 == 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else{
                j++;
            }
        }
        else{
            i++;
            if(i == (arrSize - 1))
                break;
            j = i + 1;
            countEven ++;
        }
    }
    arrSize = countEven;
}

void  splitParity(int arr[], int arrSize){
    int i,j,temp;
    i = 0;
    j = arrSize -1;
    while(i < j) {
        while (i < j && arr[i] % 2 == 1) {
            i++;
        }
        while (i < j && arr[j] % 2 == 0) {
            j--;
        }
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

