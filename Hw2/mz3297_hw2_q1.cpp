#include <iostream>
using namespace std;

int main() {

    int numberOfQuarters, numberOfDimes, numberOfNickels, numberOfPennies;
    int dollars, cents;
    int const QUARTERTOCENT = 25, DIMETOCENT = 10, NICKELTOCENT = 5, PENNYTOCENT = 1, DOLLARTOCENT = 100;

    cout << "Please enter number of coins:" << endl;

    cout << "# of quarters: ";
    cin >> numberOfQuarters;

    cout << "# of dimes: ";
    cin >> numberOfDimes;

    cout << "# of nickels: ";
    cin >> numberOfNickels;

    cout << "# of pennies: ";
    cin >> numberOfPennies;

    dollars = (numberOfQuarters * QUARTERTOCENT + numberOfDimes * DIMETOCENT + numberOfNickels * NICKELTOCENT
               + numberOfPennies * PENNYTOCENT)/DOLLARTOCENT;

    cents = (numberOfQuarters * QUARTERTOCENT + numberOfDimes * DIMETOCENT + numberOfNickels * NICKELTOCENT
             + numberOfPennies * PENNYTOCENT)%DOLLARTOCENT;

    cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;

    return 0;
}

