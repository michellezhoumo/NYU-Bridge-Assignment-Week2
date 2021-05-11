#include <iostream>
#include <string>
using namespace std;
const double POUNDTOKG = 0.453592, INCHTOM = 0.0254;

int main() {
    double weight, height, Bmi;
    string weightStatus;

    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    Bmi = weight * POUNDTOKG / pow (height * INCHTOM, 2);

    if (Bmi < 18.5)
        weightStatus = "Underweight";
    else if (Bmi >= 18.5 && Bmi < 25)
        weightStatus = "Normal";
    else if (Bmi >= 25 && Bmi < 30)
        weightStatus = "Overweight";
    else
        weightStatus = "Obese";

    cout << "The weight status is: " + weightStatus << endl;

    return 0;
}
