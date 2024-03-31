/*
    Student Name: Ngi Bujri
    File Name: Ch04Exercise16
    Date: 03/30/2024
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
    double netPrice;
    int salesEstimate;
    const double manuscriptPayment = 5000;
    const double publishingPayment = 20000;
    const double option2Royalties = 0.125;
    const double option3Royalties = 0.1;
    const double option3AdjustedRoyalties = 0.14;

    // get the net price of each novel
    cout << "\n\n  Enter the net price of each novel: $";
    cin >> netPrice;

    // get the estimated amount of novel sales
    cout << "\n  Enter estimated amount of copies to be sold: ";
    cin >> salesEstimate;

    // calcuate payment of option 1
    double option1Total = manuscriptPayment + publishingPayment;

    // calculate payment of option 2
    double option2Total = (option2Royalties * netPrice) * salesEstimate;

    // calculate payment of option 3
    double option3Total;
    // calculation for where sales estimated are less than or equal to 4000
    if (salesEstimate <= 4000) {
        option3Total = (option3Royalties * netPrice) * salesEstimate;
    }
    // calcualtions for where sales estimated are greater than 4000
    else {
        // calculate royalties from first 4000 copies
        double baseRoyalties = (option3Royalties * netPrice) * 4000;
        // calculate royalties for copies sold over 4000
        double adjustedRoyalties = (option3AdjustedRoyalties * netPrice) * (salesEstimate - 4000);
        // total royalties
        option3Total = baseRoyalties + adjustedRoyalties;
    }

    // output the total royalties for each option
    // set to two decimal places
    cout << fixed << setprecision(2);
    // set thousands separator
    locale loc("");
    cout.imbue(loc);
    cout << "\n  --------------------" << endl;
    cout << "\n  Option 1 Total Royalties: $" << option1Total << endl;
    cout << "\n  Option 2 Total Royalties: $" << option2Total << endl;
    cout << "\n  Option 3 Total Royalties: $" << option3Total << endl;

    // output best option
    if (option1Total > option2Total && option1Total > option3Total) {
        cout << "\n  The best option to choose is option 1." << endl;
    }
    else if (option2Total > option1Total && option2Total > option3Total) {
        cout << "\n  The best option to choose is option 2." << endl;
    }
    else if (option3Total > option1Total && option3Total > option2Total) {
        cout << "\n  The best option to choose is option 3." << endl;
    }

    cout << "\n  Press any key to continue..." << endl;

    _getch();
    return 0;
}