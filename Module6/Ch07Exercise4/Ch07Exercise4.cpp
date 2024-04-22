/*
*   Student Name: Ngi Bujri
*   FIle Name: Ch07Exercise4
*   Date: 04/21/2024
*/

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

string removeVowels(string str);
bool checkIfVowel(char str);

int main()
{
    string str;

    // get string from user
    cout << "\n\n  Enter a string: ";
    cin >> str;

    // display old and new string
    cout << "\n  Old String: " << str << endl;
    cout << "\n  New String: " << removeVowels(str) << endl;
    cout << "\n  Press any key to continue..." << endl;

    _getch();
    return 0;
}

// removes vowels from string
string removeVowels(string str) {
    // stores string with removed vowels
    string newString;
    for (int i = 0; i < str.length(); i++) {
        // add letter to newString if not a vowel
        if (!checkIfVowel(str[i])) newString += str[i];
    }

    return newString;
}

// check if current char is a vowel
bool checkIfVowel(char str) {
    return (
        str == 'A' || str == 'a' ||
        str == 'E' || str == 'e' ||
        str == 'I' || str == 'i' ||
        str == 'O' || str == 'o' ||
        str == 'U' || str == 'u'
        );
}
