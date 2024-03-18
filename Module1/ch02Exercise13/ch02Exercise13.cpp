/*
    Student Name: Ngi Bujri
    File Name: ch02Exercise13
    Date: 03/16/2024
*/

#include <iostream>

using namespace std;
#include <conio.h>;

int main()
{
    double originalPrice, markupPercent, salesTaxRate, salesTaxAmount, totalPrice, markupAmount;

    // ask for original price
    cout << "\n\n  Enter original price of item: ";
    cin >> originalPrice;

    // ask for markup percent
    cout << "\n  Enter markup percent: ";
    cin >> markupAmount;

    // ask for salex tax percent
    cout << "\n  Enter sales tax percent: ";
    cin >> salesTaxRate;

    // calculate markup amount
    markupAmount = originalPrice * (markupAmount / 100);
    // calculate sales tax amount
    salesTaxAmount = originalPrice * (salesTaxRate / 100);
    // calculate total price
    totalPrice = originalPrice + markupAmount + salesTaxAmount;

    // display original price, sales tax, markup, and total price
    cout << "\n --------------------" << endl;
    cout << "\n  original price: $" << originalPrice << endl;
    cout << "\n  sales tax: $" << salesTaxAmount << endl;
    cout << "\n  markup: $" << markupAmount << endl;
    cout << "\n  total price: $" << totalPrice << endl;

    _getch();

    return 0;
}
