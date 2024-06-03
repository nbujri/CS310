/*
*   student name: ngi bujri
*   file name: Ch14Exercise1
*   date: 06/02/2024
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

// exception class for negative numbers
class negativeNumber {
public:
	negativeNumber() {
		message = "input cannot be a negative number.";
	}
	negativeNumber(string str) {
		message = str;
	}
	string what() {
		return message;
	}

private:
	string message;
};

// exception class for non-numbers
class nonNumber {
public:
	nonNumber() {
		message = "input cannot be a non-number.";
	}
	nonNumber(string str) {
		message = str;
	}
	string what() {
		return message;
	}

private:
	string message;
};

int main()
{
	// 1in = 2.54cm
	int ft, in, totalInches;
	double cm;
	bool valid = false;

	//set format to two decimal places
	cout << fixed << setprecision(2);

	do {
		try {
			// ask for feet and validate input
			cout << "\n\n  enter length in feet: ";
			cin >> ft;
			if (!cin) { throw nonNumber(); }
			if (ft < 0) { throw negativeNumber(); }

			// ask for inches and validate input
			cout << "\n  enter length in inches: ";
			cin >> in;
			if (!cin) { throw nonNumber(); }
			if (in < 0) { throw negativeNumber(); }

			valid = true;

			// get total legth in inches
			totalInches = (ft * 12) + in;

			// convert total inches to centimeters
			cm = totalInches * 2.54;

			// display results
			cout << "\n  " << ft << "ft. " << in << "in. = " << cm << "cm" << endl;
		}
		catch (negativeNumber msg) {
			// print error message
			cout << "\n  " << msg.what() << endl;
		}
		catch (nonNumber msg) {
			// print error message
			cout << "\n  " << msg.what() << endl;
			// clear and ignore bad input
			// allows user to re-enter input
			cin.clear();
			cin.ignore();
		}
	} while (!valid);

	cout << "\n  press any key to continue..." << endl;

	_getch();
	return 0;
}