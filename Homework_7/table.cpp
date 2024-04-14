#include "table.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Default table
table::table() {
    for (int i = 0; i < 20; i++) {

        // Initializes first name
        Person[i].setFirst("N/A");
        // Initializes last name
        Person[i].setLast("N/A");

        // Initializes birthdate
        Person[i].setBirth(0);
        // Initializes death date
        Person[i].setDeath("0");

        // Find and set age value
        Person[i].setAge(0);

        // Set biography section
        Person[i].setBiography("N/A");
    }
}

// Table copier
table::table(const table & copy) {
    for(int i = 0; i < 20; i++) {
        Person[i] = copy.Person[i];
    }
}

// Table destructor
table::~table() {

}

// Print method
void table::print() {

    for (int i = 0; i < NUM_PEOPLE; i++) {
        Person[i].print();
    }
    cout << "------------------------------------------\n\n";
}

// Read method
void table::read(const string& file) {
    ifstream list(file);

    if (list.is_open()) {


        for (int i = 0; i < 20; i++) {

            // Sets first and last name for each person element in table array
            getline(list >> ws, tempStr, ' ');
            Person[i].setFirst(tempStr);
            getline(list >> ws, tempStr, ' ');
            Person[i].setLast(tempStr);


            // Birthdate
            getline(list >> ws, tempStr, ' ');
            // Converts the getline string input into an integer for later use when calculating the age
            tempNum1 = stoi(tempStr);
            Person[i].setBirth(tempNum1);
            // Death date
            getline(list >> ws, tempStr, ' ');
            // Converts death year into int
            tempNum2 = stoi(tempStr);

            // Checks if person is still alive and sets lifespan accordingly
            if (tempNum2 == -1) {
                Person[i].setDeath(deathStr);
                tempAge = 2023 - tempNum1;
                Person[i].setAge(tempAge);
            }
            else {
                Person[i].setDeath(tempStr);
                tempAge = tempNum2 - tempNum1;
            }


            // Find and set age value
            // tempAge = tempNum2 - tempNum1;
            Person[i].setAge(tempAge);


            // Set biography section
            getline(list, tempStr);
            Person[i].setBiography(tempStr);
        }
        list.close();
    }

    // Runs if the file doesn't successfully open
    else {
        cerr << "cant find file";
    }

}

// Firstname search method
void table::firstSearch(const string& firstName) {
    bool match = false;
    for (int i = 0; i < 20; i++) {
           if (Person[i].getFirst() == firstName) {
               Person[i].print();
               match = true;
           }
    }
        if (!match) {
            cout << "There is no match to the name give.\n\n";
        }
}

// Lastname search method
void table::lastSearch(const string& lastName) {
    bool match = false;
    for (int i = 0; i < 20; i++) {
        if (Person[i].getLast() == lastName) {
            Person[i].print();
            match = true;
        }
     }
        if (!match) {
                cout << "There is no match to the name give.\n\n";
        }
}

// Birth year range search method
void table::yearSearch(int yearStart, int yearEnd) {
    bool match = false;
    for (int i = 0; i < 20; i++) {
        int b = Person[i].getBirth();
        if ((b < yearEnd) && (b > yearStart)) {
            Person[i].print();
            match = true;
        }
    }
    if (!match) {
        cout << "There are no matches to the years given.\n\n";
    }
}