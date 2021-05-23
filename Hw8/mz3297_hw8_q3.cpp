#include <iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 << "  " << res2 << endl; //should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<< res3 << "  " << res4<<endl; //should both be 3
    return 0;
}

//Version 1.
int minInArray1(int arr[], int arrSize){
    int minVal = 0;
    if(arrSize == 2){
        if(arr[0] <= arr[1])
            minVal = arr[0];
        else
            minVal = arr[1];
    }
    else{
        if(minInArray1(arr,arrSize - 1) < arr[arrSize - 1])
            minVal = minInArray1(arr,arrSize - 1);
        else
            minVal = arr[arrSize - 1];
    }
    return minVal;
}

//Version 2.
int minInArray2(int arr[], int low, int high){
    int minVal = 0;
    if(low == high) {
        minVal = arr[low];
    }
    else{
        if(arr[low] <= arr[high]) {
            high--;
            minVal = minInArray2(arr, low, high);
        }
        else{
            low ++;
            minVal = minInArray2(arr, low, high);
        }
    }
    return minVal;
}
