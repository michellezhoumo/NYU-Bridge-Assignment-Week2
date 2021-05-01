#include <iostream>
using namespace std;

void printDivisors(int num);

//Section B: Use the printDivisors function to output the divisors of a given user input
int main() {
    int n;
    cout << "Please enter a positive integer >= 2:";
    cin >> n;
    printDivisors(n);
    return 0;
}
//Section A: Print all the divisor of a number with ascending order
void printDivisors(int num){
    int i,j;
    for (i= 1; i <= sqrt(num); i++) {
        if (num % i == 0)
            cout << i << " ";
    }

    if (sqrt(num) == (int)sqrt(num))
        j = i - 2;
    else
        j = i - 1;

    for (i = j; i >= 1; i--) {
        if (num % i == 0)
            cout << num/i << " ";
    }
}
