// M5Discussion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

using namespace std;

double compareNumbers(double x, double y);

int main()
{
    double x, y;

    cout << "\n\n  Enter the first number: ";
    cin >> x;

    cout << "\n  Enter the second number: ";
    cin >> y;

    cout << "\n  The larger number is " << compareNumbers(x) << endl;
    cout << "\n  Press any key to continue..." << endl;

    _getch();
    return 0;
}

double compareNumbers(int x, int y) {
    if (x >= y) return x;
    else return y;
}
