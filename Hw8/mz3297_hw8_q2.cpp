#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int size = 4;
    int a[] = {2,-1,3,10};
    cout << "The given arr is: ";
    for(int i : a){
        cout << i << "  ";
    }
    cout << endl;
    cout << "Sum of Square = " << sumOfSquares(a, size) << endl;
    cout << "Is the given arr in ascending order? (True/False): ";
    if(isSorted(a,size))
        cout << "True";
    else
        cout << "False";
    cout << endl;
    return 0;
}

//Section a. Return the sum of squares  of each values in arr.
int sumOfSquares(int arr[], int arrSize){
    int numSquare = 0;
    if(arrSize == 1) {
        numSquare = arr[0] * arr[0];
        return numSquare;
    }
    else{
        return sumOfSquares(arr, arrSize - 1) + arr[arrSize - 1] * arr[arrSize - 1];
    }
}

//Section b. Return bool of whether the given arr is in ascending order.
bool isSorted(int arr[], int arrSize){
    if(arrSize == 2){
        return arr[1] >= arr[0];
    }
    else{
        return (isSorted(arr,arrSize - 1) && arr[arrSize - 1] >= arr[arrSize - 2]);
    }
}