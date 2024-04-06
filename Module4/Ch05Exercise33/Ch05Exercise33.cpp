/*
    Student Name: Ngi Bujri
    File Name: Ch05Exercise33
    Date: 04/06/2024
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int a, b, t;
    int completedDishes = 0;
    int minutesPassed = 0;
    int currentPrepTime;

    // get minutes needed to complete first dish
    cout << "\n\n  How many minutes will it take to prepare the first dish? ";
    cin >> a;

    // get minutes that will be added for every following dish
    /*
        Ex: a = 10, b = 5
        1st dish: 10 min
        2nd dish: 15 min
        3rd dish: 20 min
        4th dish: 25 min
    */
    cout << "\n  How many minutes will be added for each following dishes? ";
    cin >> b;

    // get time limit to prepare dishes
    cout << "\n  How many minutes is there to prepare all the dishes? ";
    cin >> t;

    // set current prep time to first dish time
    currentPrepTime = a;
    while (minutesPassed <= t) {
        // calculate minutes passed
        minutesPassed += currentPrepTime;
        // calculate prep time for next dish
        currentPrepTime += b;
        // if enough time to complete next dish, increase count
        if (minutesPassed <= t) completedDishes++;
    }

    // output number of dishes that can be prepared
    cout << "\n  You can prepare " << completedDishes << " dishes in " << t << " minutes." << endl;
    cout << "\n  Press any key to continue..." << endl;

    _getch();
    return 0;
}

