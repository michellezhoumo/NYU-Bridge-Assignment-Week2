#include <iostream>
#include <string>
using namespace std;


int main() {
    string status,name;
    int currYear, gradYear;
    int const FOURYEAR = 4;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> gradYear;
    cout << "Please enter current year: ";
    cin >> currYear;

    if (currYear  >= gradYear)
        status = "Graduate";
    else if (currYear == gradYear - FOURYEAR)
        status = "Freshman";
    else if (currYear == gradYear - FOURYEAR + 1)
        status = "Sophomore";
    else if (currYear == gradYear - FOURYEAR + 2)
        status = "Junior";
    else if (currYear == gradYear - FOURYEAR + 3)
        status = "Senior";
    else
        status = "not in college yet";

    cout << name << ", you are a " << status << endl;

    return 0;
}
