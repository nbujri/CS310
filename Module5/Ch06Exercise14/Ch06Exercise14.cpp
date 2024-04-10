/*
*   Student Name: Ngi Bujri
*   File Name: Ch06Exercise14
*   Date: 04/09/2024
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

double highIncomeTax(double hourlyRate, double consultingMinutes);
double lowIncomeTax(double hourlyRate, double consultingMinutes);

int main()
{
    double hourlyRate, income, totalCharge, consultingMinutes;

    // get hourly rate for consultation
    cout << "\n\n  Enter hourly rate: $";
    cin >> hourlyRate;
    //cout << "\n  rate: " << hourlyRate << endl;

    // get consulting time in minutes
    cout << "\n  Enter total consulting time in minutes: ";
    cin >> consultingMinutes;
    //cout << "\n  minutes: " << consultingMinutes << endl;

    // get yearly income
    cout << "\n  Enter yearly income: ";
    cin >> income;
    //cout << "\n  income: " << income << endl;

    // if income > 25000, check if consulting time over 20 minutes
    if (income > 25000) {
        // if consulting minutes <= 20, do not chrage
        if (consultingMinutes <= 20) {
            totalCharge = 0;
        }
        else {
            totalCharge = highIncomeTax(hourlyRate, consultingMinutes);
        }
    }
    // if income <= 25000, check if consulting time <= 30 minutes
    else
    {
        // if consulting minutes <= 30, do not charge
        if (consultingMinutes <= 30) {
            totalCharge = 0;
        }
        else {
            totalCharge = lowIncomeTax(hourlyRate, consultingMinutes);
        }
    }

    // set to decimal to two places and include thousands separator
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    // display bill
    cout << "\n  --------------------" << endl;
    cout << "\n  Amount Due: $" << totalCharge << endl;
    cout << "\n  Enter any key to continue..." << endl;

    _getch();
    return 0;
}

// calculates bill for high income customers
double highIncomeTax(double hourlyRate, double consultingMinutes) {
    // only charge for minutes after the first 20
    double minutesToCharge = consultingMinutes - 20;
    return hourlyRate * .70 * (minutesToCharge / 60);
}

// calculates bill for low income customers
double lowIncomeTax(double hourlyRate, double consultingMinutes) {
    // only charge for minutes after the first 30
    double minutesToCharge = consultingMinutes - 30;
    return hourlyRate * .40 * (minutesToCharge / 60);
}