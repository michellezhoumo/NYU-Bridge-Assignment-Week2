#include <iostream>
using namespace std;

int main() {

    int daysWorkedJohn, hoursWorkedJohn, minutesWorkedJohn;
    int daysWorkedBill, hoursWorkedBill, minutesWorkedBill;
    int totalDays, totalHours, totalMinutes;
    int HOURTOMINUTES = 60, DAYTOHOUR = 24;

    cout << "Please enter the number of days John has worked: ";
    cin >> daysWorkedJohn;
    cout << "Please enter the number of hours John has worked: ";
    cin >> hoursWorkedJohn;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> minutesWorkedJohn;
    cout << "\n";

    cout << "Please enter the number of days Bill has worked: ";
    cin >> daysWorkedBill;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hoursWorkedBill;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> minutesWorkedBill;

    totalMinutes = (minutesWorkedBill + minutesWorkedJohn) % HOURTOMINUTES;
    totalHours = (hoursWorkedBill + hoursWorkedJohn + (minutesWorkedBill + minutesWorkedJohn) / HOURTOMINUTES)
            % DAYTOHOUR;
    totalDays = daysWorkedBill + daysWorkedJohn + (hoursWorkedBill + hoursWorkedJohn + (minutesWorkedBill +
            minutesWorkedJohn) / HOURTOMINUTES) / DAYTOHOUR;

    cout << "\nThe total time both of them worked together is: " << totalDays << " days, " << totalHours <<
    " hours and " << totalMinutes << " minutes.";

    return 0;
}
