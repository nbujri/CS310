/*
*   student name: ngi bujri
*   file name: Ch13Exercise17.cpp
*   date: 05/26/2024
*/

#include <iostream>
#include <conio.h>
#include <random>

using namespace std;

int main()
{
    random_device rdevice{};
    default_random_engine num{ rdevice() };
    uniform_int_distribution<int> randomNum{ 10, 100 };

    for (int i = 0; i < 25; i++) {
        if (i == 24) {
            cout << randomNum(num) << endl;
        }
        else {
            cout << randomNum(num) << ", ";
        }
    }

    cout << "\n  press any key to continue..." << endl;

    _getch();
    return 0;
}