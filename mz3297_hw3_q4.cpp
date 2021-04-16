#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    double number;
    int rounding_method;

    cout << "Please enter a Real number: " << endl;
    cin >> number;
    cout << "Choose your rounding method:" << endl;
    cout << "1. Floor round"<< endl;
    cout << "2. Ceiling round"<< endl;
    cout << "3. Round to the nearest whole number" << endl;

    cin >> rounding_method;

    switch (rounding_method){

        case FLOOR_ROUND:
            number = floor(number);
            break;
        case CEILING_ROUND:
            number = ceil(number);
            break;
        case ROUND:
            number = round(number);
            break;
    }

    cout << number;

    return 0;
}
