/*
*   Student Name: Ngi Bujri
*   File Name: M7Discussion
*   Date: 04/25/2024
*/

#include <iostream>
#include <conio.h>

using namespace std;

const int columns = 4;
const int rows = 4;

void sumOfRows(int matrix[][columns], int rows);

int main()
{
    // declare array
    int numbers[rows][columns] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "\n\n  The sum of each rows are:" << endl;
    //call sumOfRows
    sumOfRows(number, rows);

    _getch();
    return 0;
}

// calculates the sum of each row in an array
void sumOfRows(int matrix[][columns], int rows) {
    int sum;
    // loop through row
    for (int row = 0; row < rows; row+) {
        sum = 0;
        // loop through col
        for (int col = 0; col < columns; col+) {
            sum = sum + matrix[row][col];
        }
        cout << "\n  row " << (row + 1) << " = " << sum << endl;
    };
}
