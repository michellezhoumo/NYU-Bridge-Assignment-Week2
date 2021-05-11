#include <iostream>
using namespace std;

int main() {
    int dollars, cents, totalCents;
    int const QUARTERTOCENT = 25, DIMETOCENT = 10, NICKELTOCENT = 5, PENNYTOCENT = 1, DOLLARTOCENT = 100;
    int numberOfQuarters, numberOfDimes, numberOfNickels, numberOfPennies;

    cout << "PLease enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    totalCents = cents + dollars * DOLLARTOCENT;
    numberOfQuarters = totalCents/ QUARTERTOCENT;
    numberOfDimes = (totalCents % QUARTERTOCENT) / DIMETOCENT;
    numberOfNickels = (totalCents % QUARTERTOCENT % DIMETOCENT) / NICKELTOCENT;
    numberOfPennies = (totalCents % QUARTERTOCENT % DIMETOCENT % NICKELTOCENT) / PENNYTOCENT;

    cout << dollars << " dollars and " << cents << " cents are:" << endl;
    cout << numberOfQuarters << " quarters, " << numberOfDimes << " dimes, " << numberOfNickels <<
    " nickels and " << numberOfPennies << " pennies";

    return 0;
}
