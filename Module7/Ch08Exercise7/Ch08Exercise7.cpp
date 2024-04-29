/*
*   Student Name: Ngi Bujri
*   File Name: Ch08Exercise7
*   Date: 04/22/2024
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

const int numOfCandidates = 5;

int getWinner(int votes[]);
int getTotalVotes(int votes[]);
void displayResults(string candidates[], int votes[], double percentages[]);

int main()
{
    // array of candidates
    string candidates[numOfCandidates];
    // array of votes for each candidate
    int numOfVotes[numOfCandidates];
    // array of percentages of votes for each candidate
    double percentages[numOfCandidates];

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

    double totalVotes = getTotalVotes(numOfVotes);

    // calculate percentage of votes for each candidate
    for (int i = 0; i < numOfCandidates; i++) {
        double percent = (numOfVotes[i] * 100) / totalVotes;
        percentages[i] = percent;
    }

    // set percentages to two decimal places
    cout << fixed << setprecision(2);
    displayResults(candidates, numOfVotes, percentages);

    cout << "\n  Press any key to continue..." << endl;

    _getch();
    return 0;
}

// returns the total number of votes received
int getTotalVotes(int votes[]) {
    int totalVotes = 0;
    for (int i = 0; i < numOfCandidates; i++) {
        totalVotes += votes[i];
    }
    return totalVotes;
}

// returns the index of the winner of the election
int getWinner(int votes[]) {
    int leadingCandidate = 0;
    for (int i = 0; i < numOfCandidates; i++) {
        if (votes[leadingCandidate] < votes[i]) leadingCandidate = i;
    }
    return leadingCandidate;
}

// displays candidates, votes received, and the winner of the election
void displayResults(string candidates[], int votes[], double percentages[]) {
    cout << "\n  ---------- Election Results ----------" << endl;
    for (int i = 0; i < numOfCandidates; i++) {
        cout << "\n  " << candidates[i] << ": " << votes[i] << " (" << percentages[i] << "%)" << endl;
    }

    int totalVotes = getTotalVotes(votes);
    cout << "\n  Total Votes: " << totalVotes << endl;
    int winner = getWinner(votes);
    cout << "\n  The winner of the election is " << candidates[winner] << endl;
}