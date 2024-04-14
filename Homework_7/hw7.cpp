#include "table.h"
#include <iostream>
using namespace std;

// Name: Evan Meyers
// UAID: 010955257


int main() {

    cout << "---------------------\n"
         << "|Name:\tEvan Meyers |\n"
         << "|UAID:\t010955257   |\n"
         << "---------------------\n\n";

    // Initializes object and variables
    table famousPeople;
    int choice = 0, yearStart, yearEnd;
    string firstName, lastName;
    bool quit = false;

    // Reads "people.txt" file using ifstream
    famousPeople.read("people.txt");


    do {
        // Outputs menu for user
        cout << "-----------------------------------------------------\n"
                "| Choose one of the following options:              |\n"
                "|(1) Search for person using their first name       |\n"
                "|(2) Search for person using their last name        |\n"
                "|(3) Search for people using a range of birth years |\n"
                "|(4) Quit the program                               |\n"
                "-----------------------------------------------------\n";
        cin >> choice;

        // Collect user input and run integer error check
        while (choice < 1 || choice > 4) {
            cout << "Error, please enter a number 1-4\n";
            cin >> choice;
            cout << endl;
        }

        // Searches by first name
        if (choice == 1) {
            cout << "\nEnter the first name to search (Capitalization matters): ";
            cin >> firstName;
            cout << endl;
            famousPeople.firstSearch(firstName);
        }

        // Searches by last name
        else if (choice == 2) {
            cout << "\nEnter the last name to search (Capitalization matters): ";
            cin >> lastName;
            cout << endl;
            famousPeople.lastSearch(lastName);
        }

        // Searches by birth year range
        else if (choice == 3) {
            cout << "\nEnter range of birth years to search (Enter years like following example: 1900 to 1910 ---> 1900 1910): ";
            cin >> yearStart >> yearEnd;
            cout << endl;
            famousPeople.yearSearch(yearStart, yearEnd);
        }

        // Quits program
        else if (choice == 4) {
            quit = true;
        }
    }
    while (!quit);

    return 0;
}
