#include <iostream>
#include <string>
using namespace std;

const int INITINDEX=0;

int main() {
    string firstName, middleNameOrInitial, lastName;
    string newName;

    cout << "Please enter your name:" << endl;
    cin >> firstName >> middleNameOrInitial >> lastName;

    newName = lastName + ", " + firstName + " " + middleNameOrInitial[INITINDEX] + ".";
    cout << newName;
    return 0;
}
