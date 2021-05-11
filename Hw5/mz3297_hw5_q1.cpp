#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int num;
    cout << "Please enter a positive integer : ";
    cin >> num;
    cout << fib(num);
    return 0;
}

int fib(int n){
    int nthFib;
    if (n <= 2)
        nthFib = 1;
    else
        nthFib = fib(n-1) + fib(n-2);
    return nthFib;
}