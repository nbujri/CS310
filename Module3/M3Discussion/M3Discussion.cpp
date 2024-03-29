/*
    Student Name: Ngi Bujri
    File Name: M3Discussion
    Date: 03/28/2024
    Description: simple program demonstrating selection control statements with intentional errors
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int num;

    // get number
    cout << "\n\n  Enter an integer: ";
    cin >> num;

    if (num % 2 = 0) {
        cout << "\n  " << num << " is an even number." << endl;
    }
    else {
        cout << "\n  " + num + " is an odd number." << endl;
    }

    cout << "\n  Press any key to continue...\n";

    _getch();

    return 0;
}
