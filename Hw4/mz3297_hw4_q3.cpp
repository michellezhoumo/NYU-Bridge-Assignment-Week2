#include <iostream>
using namespace std;

int main() {
    int n;
    int power;
    int binaryNumber;

    cout << "Enter decimal number:" << endl;
    cin >> n;

    binaryNumber = 0;

    while(n > 0) {
        power = 0;
        while (pow(2, power) <= n) {
            power ++;
        }
        power -= 1;
        n -= pow(2, power);
        binaryNumber += pow(10,power);
    }

    cout << "The binary representation is " << binaryNumber << endl;
    return 0;
}
