/*
    Student Name: Ngi Bujri
    File Name: ch03Exercise7
    Date: 03/22/2024
    Description: program that calculates interest of credit card's unpaid balance
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
    double netBalance, payment, d1, d2, interestRate;

    // get netBalance
    cout << "\n\n  Enter your net balance: ";
    cin >> netBalance;

    // get payment
    cout << "\n  Enter payment amount: ";
    cin >> payment;

    // get number of days in billing cycle
    cout << "\n  Enter the number of days in billing cycle: ";
    cin >> d1;

    // get number of days payment is made before billing cycle
    cout << "\n  Enter the number of days payment was made before billing cycle: ";
    cin >> d2;

    // get monthly interest rate
    cout << "\n  Enter monthly interest rate percent: ";
    cin >> interestRate;

    // convert percent to decimal
    double interestPercent = interestRate / 100;

    // find the average daily balance
    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
    // calculate interest amount
    double interest = averageDailyBalance * interestPercent;

    // output the interest to two decimal places with a thousands separator
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    cout << "\n  --------------------" << endl;
    cout << "\n  Interest: $" << interest << endl;
    cout << "\n  Press any key to continue..." << endl;

    _getch();

    return 0;
}
