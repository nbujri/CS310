/*
*   Student Name: Ngi Bujri
*   File Name: CH12Exercise3
*   Date: 05/19/2024
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

int getWinner(int votes[], int size);
int getTotalVotes(int votes[], int size);
void displayResults(string candidates[], int votes[], double percentages[], int size);

int main()
{
    int numOfCandidates;

    // ask for number of candidates
    cout << "\n\n  Enter number of candidates: ";
    cin >> numOfCandidates;

    // array of candidates
    string* candidates = new string[numOfCandidates];
    // array of votes for each candidate
    int* numOfVotes = new int[numOfCandidates];
    // array of percentages of votes for each candidate
    double* percentages = new double[numOfCandidates];

    // get names of the five candidates and their number of votes
    for (int i = 0; i < numOfCandidates; i++) {
        string name;
        int votes;

        cout << "\n  Enter candidate " << (i + 1) << "'s name: ";
        cin >> name;
        candidates[i] = name;

        cout << "\n  Enter number of votes for " << candidates[i] << ": ";
        cin >> votes;
        numOfVotes[i] = votes;
    }

    double totalVotes = getTotalVotes(numOfVotes, numOfCandidates);

    // calculate percentage of votes for each candidate
    for (int i = 0; i < numOfCandidates; i++) {
        double percent = (numOfVotes[i] * 100) / totalVotes;
        percentages[i] = percent;
    }

    // set percentages to two decimal places
    cout << fixed << setprecision(2);
    displayResults(candidates, numOfVotes, percentages, numOfCandidates);

    cout << "\n  Press any key to continue..." << endl;

    _getch();
    return 0;
}

// returns the total number of votes received
int getTotalVotes(int votes[], int size) {
    int totalVotes = 0;
    for (int i = 0; i < size; i++) {
        totalVotes += votes[i];
    }
    return totalVotes;
}

// returns the index of the winner of the election
int getWinner(int votes[], int size) {
    int leadingCandidate = 0;
    for (int i = 0; i < size; i++) {
        if (votes[leadingCandidate] < votes[i]) leadingCandidate = i;
    }
    return leadingCandidate;
}

// displays candidates, votes received, and the winner of the election
void displayResults(string candidates[], int votes[], double percentages[], int size) {
    cout << "\n  ---------- Election Results ----------" << endl;
    for (int i = 0; i < size; i++) {
        cout << "\n  " << candidates[i] << ": " << votes[i] << " (" << percentages[i] << "%)" << endl;
    }

    int totalVotes = getTotalVotes(votes, size);
    cout << "\n  Total Votes: " << totalVotes << endl;
    int winner = getWinner(votes, size);
    cout << "\n  The winner of the election is " << candidates[winner] << endl;
}