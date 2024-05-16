/*
*   student name: ngi bujri
*   file name: M10Discussion
*   date: 05/16/2024
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int var1 = 100; // store 100 into var1
    int var2 = var1; // reference var1
    double* var3 = &var1; // store address of var1
    int var4 = var3; // dereference var3

    // print value of each variable
    cout << "\n  var1 value: " << var1 << endl;
    cout << "\n  var2 value: " << var2 << endl;
    cout << "\n  var3 value: " << var3 << endl;
    cout << "\n  var4 value: " << var4 << endl;

    cout << "\n  press any key to continue..." << endl;

    _getch();
    return 0;
}