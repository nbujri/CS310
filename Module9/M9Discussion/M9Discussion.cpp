/*
*   student name: ngi bujri
*   file name: M9Discussion
*   date: 05/09/2024
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

// base class
class Vehicle {
public:
    string manufacturer = "Honda";
    void drive() {
        cout << "\n  Vroom! Vroom!" << endl;
    }
};

// child 1
class Civic : public Vehicle {
public:
    string model = "Civic";

};

// child 2
class Accord {
public:
    string model = "Accord";
};

int main()
{
    Vehicle civic;
    Vehicle accord;

    civic.drive();
    cout << "\n  The " << civic.manufacturer << " " << civic.model << " drives away" << endl;

    accord.drive();
    cout << "\n  The " << accord.manufacturer << " " << accord.model << " drives away" << endl;

    cout << "\n  press any key to continue..." << endl;
    
    _getch();
    return 0;
}