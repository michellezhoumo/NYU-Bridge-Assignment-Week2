#include <iostream>
#include <string>
using namespace std;
const string TAB = "    ", EMPTYSPACEPERDAY = "       ", ONESPACE = " ", TWOSPACES = "  ";

int printMonthCalender (int numOfDays, int startingDay);
void printYearCalender (int year, int startingDay);

int main() {
    //int lastDayDayOfWeek;
    //lastDayDayOfWeek = printMonthCalender (29, 1);
    //cout << lastDayDayOfWeek;
    printYearCalender (2016, 5);
    return 0;
}

int printMonthCalender (int numOfDays, int startingDay){
    string header = "Mon" + TAB + "Tue" + TAB + "Wed" + TAB + "Thu" + TAB + "Fri" + TAB + "Sat" + TAB + "Sun";
    cout << header << endl;

    int countEmptyDays = 0, day, countDaysInWeek;
    while(countEmptyDays < startingDay - 1){
        cout << EMPTYSPACEPERDAY;
        countEmptyDays ++;
    }

    countDaysInWeek = countEmptyDays;
    for(day = 1; day <= numOfDays; day++){
        if(countDaysInWeek < 7) {
            if(day/10 >= 1)
                cout << day << TAB + ONESPACE;
            else
                cout << day << TAB + TWOSPACES;
        }
        else {
            if(day/10 >= 1)
                cout << endl << day << TAB + ONESPACE;
            else
                cout << endl << day << TAB + TWOSPACES;
            countDaysInWeek = 0;
        }
        countDaysInWeek++;
    }
    cout << endl;

    return countDaysInWeek;
}

void printYearCalender (int year, int startingDay){
    int month, monthStart, monthEnd;
    monthStart = startingDay;
    for(month = 1; month <= 12; month++) {
        string headerMonth, calHeader;
        switch(month){
            case 1:
                headerMonth = "January";
                break;
            case 2:
                headerMonth = "Feburary";
                break;
            case 3:
                headerMonth = "March";
                break;
            case 4:
                headerMonth = "April";
                break;
            case 5:
                headerMonth = "May";
                break;
            case 6:
                headerMonth = "June";
                break;
            case 7:
                headerMonth = "July";
                break;
            case 8:
                headerMonth = "August";
                break;
            case 9:
                headerMonth = "September";
                break;
            case 10:
                headerMonth = "October";
                break;
            case 11:
                headerMonth = "November";
                break;
            case 12:
                headerMonth = "December";
                break;
        }
        calHeader = headerMonth + " " + to_string(year);
        cout << calHeader << endl;

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            monthEnd = printMonthCalender(31, monthStart);
        }
        else if(month != 2) {
            monthEnd = printMonthCalender(30, monthStart);
        }
        else{
            if (year % 4 == 0){
                monthEnd = printMonthCalender(29, monthStart);
            }
            else{
                monthEnd = printMonthCalender(28, monthStart);
            }
        }
        cout << endl;
        monthStart = monthEnd + 1;

        //In case that last day of the month is Sunday (day 7 of the week), need to reset the monthStart to 0
        if(monthStart > 7)
            monthStart = 0;
    }
}