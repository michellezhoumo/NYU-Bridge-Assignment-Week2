#include <iostream>
#include <string>
using namespace std;
const int HOURTOMIN = 60, DAYTOHOUR = 24;

int main() {
    string dayOfTheWeek;
    double hourStart24, minuteStart24, cost;
    char temp = ':';
    int lengthOfCallInMinutes;

    cout << "Please enter the day of the week: ";
    cin >> dayOfTheWeek;
    cout << "Please enter the hour the long distance call started (in 24-hour format): ";
    cin >> hourStart24;
    cout << "Please enter the minute the long distance call started: ";
    cin >> minuteStart24;
    cout << "Please enter the length of the call in minutes: ";
    cin >> lengthOfCallInMinutes;

    if (dayOfTheWeek == "Mo" || dayOfTheWeek == "Tu" || dayOfTheWeek == "We" ||
    dayOfTheWeek == "Th" || dayOfTheWeek == "Fr" ) {
        if (hourStart24 < 8 || hourStart24 > 18) {
            cost = 0.25 * lengthOfCallInMinutes;
        } else {
            cost = 0.4 * lengthOfCallInMinutes;
        }
    }
    else if (dayOfTheWeek == "Sa" || dayOfTheWeek == "Su"){
        cost = 0.15 * lengthOfCallInMinutes;
    }

    cout << '\n' << "The long distance call that started at " << hourStart24  << temp  << minuteStart24
    << " and lasted " << lengthOfCallInMinutes << " minutes, will cost " << cost << " dollars.";

    return 0;
}
