#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int target;
    int guess, numGuessLeft;
    int newRangeLow, newRangeHigh;

    srand(time(0));

    target = (rand() % 100) + 1 ;
    numGuessLeft = 5;
    newRangeLow = 1;
    newRangeHigh = 100;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
    while(numGuessLeft > 0) {
        cout << "Range: [" << newRangeLow << ", " << newRangeHigh << "], Number of guesses left: " << numGuessLeft << endl;
        cout << "Your guess: ";
        cin >> guess;

        if (guess < target){
            cout << "Wrong! My number is bigger" << endl;
            newRangeLow = guess;
        }
        else if (guess > target){
            cout << "Wrong! My number is smaller" << endl;
            newRangeHigh = guess;
        }
        else{
            cout << "Congrats! You guessed my number in " << 5 - numGuessLeft + 1 << " guesses." << endl;
            break;
        }

        cout << endl;
        numGuessLeft --;
    }

    if(numGuessLeft == 0)
        cout << "Out of guesses! My number is " << target << endl;

    return 0;
}
