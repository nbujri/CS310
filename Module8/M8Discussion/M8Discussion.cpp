// M8Discussion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Dorm {
public:
    // constructor
    Dorm(string name, int id) {
        dormName = name;
        dormID = id;
    }

    string dormName;
    int dormID;
};

class Student {
private:
    string firstName;
    string lastName;
    Dorm dorm;

public:
    // constructor
    Student(string first, string last, Dorm dorm) : firstName(first), lastName(last), dorm(dorm) {}

    // display student information
    void displayStudentInfo() {
        cout << "\n  student name: " << firstName << " " << lastName << " || dorm: " << dorm.dormName << " (" << dorm.dormID << ")" << endl;
    }
};


int main()
{
    // dorm objects
    Dorm dorm1 = Dorm("North Dorm", 1);
    Dorm dorm2 = Dorm("South Dorm", 2);

    //student objects
    Student student1 = Student("john", "doe");
    Student student2 = Student("jane", "doe", dorm2);

    // display info for student 1 and 2
    student1.displayStudentInfo();
    student2.displayStudentInfo;

    cout << "\n  press any key to continuee..." << endl;

    _getch();
    return 0;
}

