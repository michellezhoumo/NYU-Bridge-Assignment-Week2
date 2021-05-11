#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUMOFDIGITS = 10;
const int PIN = 12345;

void printNumSequence(int a[], int size);
bool isPIN(int userPIN, int ar[]);

int main() {
    int numToAdd, arr[NUMOFDIGITS],i,inputPIN;
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN: ";
    for(i=0; i < 10; i++){
        cout << i << " ";
    }
    cout << endl << "NUM: ";
    printNumSequence(arr, NUMOFDIGITS);
    cout << endl;

    cin >> inputPIN;
    if(isPIN(inputPIN, arr))
        cout << "Your PIN is correct";
    else
        cout << "Your PIN is not correct";

    return 0;
}

//generate a num array containing num 1,2 and 3 to map the password onto;
void printNumSequence(int a[], int size){
    srand (time(NULL));
    int i, numToAdd;
    for (i=0; i < size; i++) {
        numToAdd = rand() % 3 + 1;
        a[i] = numToAdd;
        cout <<  a[i] << " ";
    }
}

//Compare the userInput with preset password, return true if the same, false otherwise
bool isPIN(int userPIN, int ar[]){
    bool correctPIN = true;
    int pin = PIN;
    while(userPIN > 0 && pin > 0){
        if (ar[pin % 10] != userPIN % 10){
            correctPIN = false;
            break;
        }
        userPIN /= 10;
        pin /= 10;
    }
    return correctPIN;
}
