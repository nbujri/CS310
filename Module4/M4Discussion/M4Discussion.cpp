/*
    Student Name: Ngi Bujri
    File Name: M4Discussion
    Date: 04/04/2024
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int num;
    int counter = 0;

    cout << "\n\n  Enter a number to count to: ";
    cin >> num;

    cout << "\n  ";

    while counter <= num {
        if (counter == num) cout << counter << endl;
        else {
            cout << counter << " ";
        }
        counter+;
    }

    cout << "\n  Press any key to continue..." << endl;

    _getch();
    return 0;
}

