#include <iostream>
#include <limits>
using namespace std;


int minInArray(int arr[], int arrSize);
void printMinValIndex(int arr[], int arrSize);

int main() {
    int ar[25],count,num;
    cout << "Please enter 20 integers separated by a space:"<< endl;
    //Section 1. - read using input total of 20 integers into the ar;
    count = 0;
    while (count < 20){
        cin >> num;
        ar[count] = num;
        count ++;
    }

    //Section 2. - find from the ar the index of all instances that has the minVal;
    cout << "The minimum value is " << minInArray(ar,count) << ", and it is located in the following indices: ";
    printMinValIndex(ar, count);
    return 0;
}

//Section 1. - Returns the minimum value in an arr with logical size arrSize
int minInArray(int arr[], int arrSize){
    int i,minVal;
    minVal = INT_MAX;
    for (i = 0; i < arrSize; i++){
        if (arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}

//Section 2. - Use minInArray function and output all indices that contains the minVal;
void printMinValIndex(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++){
        if (arr[i] == minInArray(arr,arrSize))
            cout << i << " ";
    }
}