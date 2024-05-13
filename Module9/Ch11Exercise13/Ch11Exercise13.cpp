/*
*   student name: ngi bujri
*   file name: Ch11Exercise13
*   date: 05/12/2024
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

// base class
class bankAccount {
public:
    int accountNumber;
    double balance;

    bankAccount(int an, double b) : accountNumber(an), balance(b) {}

    // set account number
    void setAccountNumber(int num) {
        accountNumber = num;
    }

    //get account number
    int getAccountNumber() {
        return accountNumber;
    }

    // get account balance
    double getBalance() {
        return balance;
    }

    // deposit money to account
    void deposit(double amount) {
        balance += amount;
    }

    // withdraw money from account
    virtual void withdraw(double amount) {
        balance -= amount;
    }

    // print account information
    virtual void displayAccountInformation() {
        cout << "\n  account number: " << accountNumber << endl;
        cout << "\n  account balance: $" << balance << endl;
    }

};

class checkingAccount : public bankAccount {
public:
    checkingAccount(int an, double b, double i, double min, double sc) : bankAccount(an, b), interest(i), minBalance(min), serviceCharge(sc) {};

    // set interest rate for account
    void setInterest(double i) {
        interest = i;
    }

    // get interest rate for account
    double getInterest() {
        return interest;
    }

    // set minimum balance
    void setMinBalance(double b) {
        minBalance = b;
    }

    // get minimum balance
    double getMinBalance() {
        return minBalance;
    }

    // set service charge fee
    void setServiceCharge(double charge) {
        serviceCharge = charge;
    }

    // get service charge
    double getServiceCharge() {
        return serviceCharge;
    }

    // post interest
    void postInterest() {
        balance += balance * interest;
    }

    // verifies if account balance is less than minimum balance
    bool verifyBalance() {
        return balance < minBalance;
    }

    // writes check
    void writeCheck() {
        return;
    }

    // withdraw money
    void withdraw(double amount) override {
        balance -= amount;
    }

    // print account information
    void displayAccountInformation() override {
        bankAccount::displayAccountInformation();
        cout << "\n  interest rate: " << interest << " (" << interest * 100 << " %)" << endl;
        cout << "\n  minimum balance: $" << minBalance << endl;
        cout << "\n  service charge: $" << serviceCharge << endl;
    }

private:
    double interest;
    double minBalance;
    double serviceCharge;
};

class savingsAccount : public bankAccount {
public:
    savingsAccount(int an, double b, double i) : bankAccount(an, b), interest(i) {};

    // deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // withdraw money
    void withdraw(double amount) override {
        balance -= amount;
    }

    // set interest rate
    void setInterest(double i) {
        interest = i;
    }

    // get interest rate
    double getInterest() {
        return interest;
    }

    // post interest
    void postInterest() {
        balance += balance * interest;
    }

    // print account information
    void displayAccountInformation() override {
        bankAccount::displayAccountInformation();
        cout << "\n  interest rate: " << interest << " (" << interest * 100 << " %)" << endl;
    }

private:
    double interest;
};

// perform account actions
void manageChecking(checkingAccount account) {
    int choice;
    double amount;

    do {
        cout << "\n  1. view account information" << endl;
        cout << "\n  2. deposit" << endl;
        cout << "\n  3. withdraw" << endl;
        cout << "\n  4. pay service charge" << endl;
        cout << "\n  5. post interest" << endl;
        cout << "\n  6. exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.displayAccountInformation();
            break;
        case 2:
            cout << "\n  enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 3:
            cout << "\n  enter withdrawal amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 4:
            if (account.balance < account.getMinBalance()) {
                account.balance -= account.getServiceCharge();
            }
            else
            {
                cout << "\n  balance meets minimum amount requirements." << endl;
            }
            break;
        case 5:
            account.postInterest();
        case 6:
            break;
        default:
            cout << "\n  invalid input. try again." << endl;
        }
    } while (choice != 6);
}

// perform account actions
void manageSavings(savingsAccount account) {
    int choice;
    double amount;

    do {
        cout << "\n  1. view account information" << endl;
        cout << "\n  2. deposit" << endl;
        cout << "\n  3. withdraw" << endl;
        cout << "\n  4. post interest" << endl;
        cout << "\n  5. exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.displayAccountInformation();
            break;
        case 2:
            cout << "\n  enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 3:
            cout << "\n  enter withdrawal amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 4:
            account.postInterest();
            break;
        case 5:
            break;
        default:
            cout << "\n  invalid input. try again." << endl;
        }
    } while (choice != 5);
}

int main()
{
    // format numbers
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    // create checking and savings account to test
    checkingAccount checking(1, 10000.00, 0.05, 500, 10);
    savingsAccount savings(2, 5000.00, .1);

    // store user choice
    int choice;
    do {
        cout << "\n  1. manage checking account" << endl;
        cout << "\n  2. manage savings account" << endl;
        cout << "\n  3. exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            manageChecking(checking);
            break;
        case 2:
            manageSavings(savings);
            break;
        case 3:
            break;
        default:
            cout << "\n  invalid input. please enter 1 or 2." << endl;
        }
    } while (choice != 3);

    cout << "\n  press any key to continue..." << endl;

    _getch();
    return 0;
}
