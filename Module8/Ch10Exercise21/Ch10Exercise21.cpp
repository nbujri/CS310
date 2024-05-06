/*
*   student name: ngi bujri
*   file name: Ch10Exercise21
*   date: 05/04/2024
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string name; // name of account holder
    int accountNumber; // account number
    static int tempNumber; // static member used to automatically assign an account number
    string accountType; // type of bank accout (checking/saving)
    double balance;
    double interestRate; // interest rate to be stored as a decimal

public:
    // constructor
    BankAccount(string n, string t, double b, double i) {
        name = n;
        accountType = t;
        balance = b;
        interestRate = i;
        // account number automatically assigned through incrementation
        accountNumber = tempNumber++;
    }

    // getters
    string getName() {
        return name;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountType() {
        return accountType;
    }

    double getBalance() {
        return balance;
    }

    double getInterestRate() {
        return interestRate;
    }

    // setters
    void setName(string name) {
        name = name;
    }

    void setAccountType(string accoutType) {
        accountType = accoutType;
    }

    void setBalance(double balance) {
        balance = balance;
    }

    void setInterestRate(double interestRate) {
        interestRate = interestRate;
    }

    // add depost to balance and display new balance
    void deposit(double depositAmount) {
        if (depositAmount < 0) {
            cout << "\n  deposit must be more than $0." << endl;
        }
        else
        {
            balance += depositAmount;
            cout << "\n  current balance: $" << balance << endl;
        }
    }

    // withdraw money from bank account
    void withdraw(double withdrawalAmount) {
        // check if there is enough to withdraw
        if (balance < withdrawalAmount) {
            cout << "\n  account balance is too low! current balance is $" << balance << endl;
        }
        else {
            // withdraw if there is enough money and display new balance
            balance -= withdrawalAmount;
            cout << "\n  current balance: $" << balance << endl;
        }
    }

    // display account information
    void displayAccountInfo() {
        // format numbers
        cout << fixed << setprecision(2);
        locale loc("");
        cout.imbue(loc);
        //print info
        cout << "\n  ---------- account information ----------" << endl;
        cout << "\n  name: " << name << endl;
        cout << "\n  account number: " << accountNumber << endl;
        cout << "\n  account type: " << accountType << endl;
        cout << "\n  balance: $" << balance << endl;
        cout << "\n  interest rate: "  << interestRate << " (" << (interestRate * 100) << "%)" << endl;
    }


};

// initialize account number
int BankAccount::tempNumber = 100;

// set number of accounts to store
const int numOfAccounts = 10;

// finds account with matching account number
int findAccount(BankAccount accounts[]) {
    int accountNumber, index;
    bool found = false;
    while (!found) {
        cout << "\n  enter account number (100 - 109): ";
        cin >> accountNumber;
        for (int i = 0; i < numOfAccounts; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                // store index of matching account
                index = i;
                found = true;
            }
        }
        if (!found) {
            cout << "\n  no account exists. try again. " << endl;
        }
    }
    return index;
}

// perform account actions
void manageAccount(BankAccount accounts[], int accountIndex) {
    int choice;
    double amount;

    do {
        cout << "\n  1. view account information" << endl;
        cout << "\n  2. deposit" << endl;
        cout << "\n  3. withdraw" << endl;
        cout << "\n  4. exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            accounts[accountIndex].displayAccountInfo();
            break;
        case 2:
            cout << "\n  enter amount to deposit: ";
            cin >> amount;
            accounts[accountIndex].deposit(amount);
            break;
        case 3:
            cout << "\n  enter withdrawal amount: ";
            cin >> amount;
            accounts[accountIndex].withdraw(amount);
            break;
        case 4:
            break;
        default:
            cout << "\n  invalid input. try again." << endl;
        }
    } while (choice != 4);
}

int main()
{
    // format numbers
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    // create and store 10 accounts
    BankAccount accounts[numOfAccounts] = {
        BankAccount("Bob", "checking", 10000.00, 0.05),
        BankAccount("John", "saving", 5000.50, 0.10),
        BankAccount("Sarah", "checking", 8000.00, 0.07),
        BankAccount("Joe", "checking", 6500.00, 0.05),
        BankAccount("Lara", "checking", 4400.00, 0.10),
        BankAccount("Donald", "saving", 1000.00, 0.06),
        BankAccount("Goofy", "saving", 2000.00, 0.07),
        BankAccount("Mickey", "checking", 20000.00, 0.08),
        BankAccount("Mario", "checking", 15000.00, 0.10),
        BankAccount("Luigi", "saving", 12000.00, 0.10),
    };

    // store user choice
    int choice;
    //stores index when searching for account
    int accountIndex;
    // prompt user to log in or exit program
    do {
        cout << "\n  1. log in" << endl;
        cout << "\n  2. exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            accountIndex = findAccount(accounts);
            manageAccount(accounts, accountIndex);
            break;
        case 2:
            break;
        default:
            cout << "\n  invalid input. try again." << endl;
        }
    } while (choice != 2);

    cout << "\n  press any key to continue..." << endl;

    _getch();
    return 0;
}