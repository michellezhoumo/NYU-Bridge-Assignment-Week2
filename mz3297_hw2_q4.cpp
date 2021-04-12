#include <iostream>
using namespace std;

int main() {
    int integer1, integer2;
    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin >> integer1 >> integer2;
    cout << integer1 << " + " << integer2 << " = " << (integer1 + integer2) << endl;
    cout << integer1 << " - " << integer2 << " = " << (integer1 - integer2) << endl;
    cout << integer1 << " * " << integer2 << " = " << (integer1 * integer2) << endl;
    cout << integer1 << " / " << integer2 << " = " << (double(integer1) / integer2) << endl;
    cout << integer1 << " div " << integer2 << " = " << (integer1 / integer2) << endl;
    cout << integer1 << " mod " << integer2 << " = " << (integer1 % integer2) << endl;

    return 0;
}
