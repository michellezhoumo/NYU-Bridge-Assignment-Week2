#include <iostream>
#include <vector>
using namespace std;

const int INDICATOR = -1;
void main1(int* arrNum, int arrSize, int target);
void main2(int* arrNum, int arrSize, int target);

int main() {
    int num, * numArr, size = 0, i = 0, targetNum;
    numArr = new int[size];

    cout << "Please enter a sequence of positive integers, each in a separate line.\n"
            "End you input by typing -1." << endl;
    while (true){
        cin >> num;
        if(num == INDICATOR)
            break;
        size ++;
        numArr[i] = num;
        i++;
    }

    cout << "Please enter a number you want to search:" << endl;
    cin >> targetNum;

    //Implementation 1. Using heap dynamic array
    cout << "Implementation 1. Output" << endl;
    main1(numArr, size, targetNum);
    cout << endl;
    //Implementation 2. Using vector
    cout << endl << "Implementation 2. Output" << endl;
    main2(numArr, size, targetNum);

    delete [] numArr;
    return 0;
}

//Implementation 1. Using heap dynamic array

void main1(int* arrNum, int arrSize, int target){
    int sizeWithTarget=0,j = 0;
    int *temp = new int [sizeWithTarget];

    for(int i = 0; i < arrSize; i++){
        if (arrNum[i] == target){
            sizeWithTarget ++;
            temp[j] = i + 1;
            j++;
        }
    }
    if (* temp == NULL) {
        cout << "No matching element in given array.";
    }
    else {
        cout << target << " shows in lines ";
        for (int k = 0; k < sizeWithTarget; k++)
            if (k == sizeWithTarget - 1)
                cout << temp[k] << ".";
            else
                cout << temp[k] << ",";
    }

    delete[] temp;
}

//Implementation 2. Using vector
void main2(int* arrNum, int arrSize, int target){
    vector<int> temp;
    for (int i = 0; i < arrSize; i++){
        if (arrNum[i] == target)
            temp.push_back(i + 1);
    }
    if(temp.size() == 0) {
        cout << "No matching element in given array.";
    }
    else {
        cout << target << " shows in lines ";
        for (int i = 0; i < temp.size(); i++){
            if(i == temp.size()-1)
                cout << temp[i] << ".";
            else
                cout << temp[i] << ",";
        }
    }
}