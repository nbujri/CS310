/*
*   student name: ngi bujri
*   file name: M11Discussion
*   date: 05/23/2024
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

template <class T>
GetAverage(T numbers[], T size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

int main()
{
    cout << fixed << setprecision(2);
    const int size = 6;
    double nums[size] = { 1 , 2, 3, 4, 5, 6 };
    double avg = GetAverage(nums, size);

    cout << "\n\n  average = " << avg << endl;
    cout << "\n  press any key to continue..." << endl;

    _getch();
    return 0;
}