#include <iostream>
using namespace std;
void oddsKeepEvensFlip(int arr[], int arrSize);
int main() {
    int ar1Size = 6, ar2Size = 11, ar3Size = 4;
    //Test case 1
    int ar1[] = {5,2,11,7,6,4};
    oddsKeepEvensFlip(ar1, ar1Size);
    //Test case 2
    int ar2[] = {1,1,88,6,73,4,6,7,20,2,9};
    oddsKeepEvensFlip(ar2, ar2Size);
    //Test case 3
    int ar3[] = {16,3,25,4};
    oddsKeepEvensFlip(ar3, ar3Size);
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
    int * temp = new int[arrSize]{0};
    int j = 0;

    //put all odd numbers into heap dynamic array -- temp
    for (int i= 0; i < arrSize; i ++){
        if (arr[i] % 2 == 1) {
            temp[j] = arr[i];
            j++;
        }
    }
    //Starting from the end of the sequence, read even numbers after
    //the odd into heap dynamic array -- temp
    for (int i= arrSize-1; i >= 0; i --){
        if (arr[i] % 2 == 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    //Output the rearranged array, re-assign back to arr[] input, to the same address
    cout << "arr = {" ;
    for(int i = 0; i < arrSize; i ++){
        arr[i] = temp[i];
        if(i == arrSize -1)
            cout << arr[i];
        else
            cout << arr[i] << ", ";
    }
    cout << "}" << endl;
    delete[] temp;
}