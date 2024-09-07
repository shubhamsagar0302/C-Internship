#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Function to get the computer's choice
int getComputerChoice() {
    return rand() % 3; // Randomly returns 0, 1, or 2
}

// Function to convert numeric choice to string
string getChoiceName(int choice) {
    switch (choice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "Invalid choice";
    }
}

// Function to determine the winner
void determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == 0 && computerChoice == 2) ||  // Rock beats Scissors
               (userChoice == 1 && computerChoice == 0) ||  // Paper beats Rock
               (userChoice == 2 && computerChoice == 1)) {  // Scissors beat Paper
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    srand(time(0));  // Seed the random number generator

    int userChoice;
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
    cin >> userChoice;

    if (userChoice < 0 || userChoice > 2) {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    int computerChoice = getComputerChoice();

    cout << "You chose: " << getChoiceName(userChoice) << endl;
    cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

    determineWinner(userChoice, computerChoice);

    return 0;
}
