#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream dict;
    // File location of my "dictionary.txt" file
    dict.open("C:\\Users\\minec\\source\\repos\\Homework 5\\dictionary.txt");
    const int wordNum = 129;
    string lang, eng [wordNum], span [wordNum], word;
    int index = -1;

    if (dict.is_open()) {
        // Reads the "dictionary.txt" file and copies the English words to eng[] and the Spanish words to span[]
        for (int i = 0; i < wordNum; i++) {
            getline (dict >> ws, eng[i], ' ');
            getline (dict, span[i]);
        }
        dict.close();
    }
    else {
        // Error in the case that the "dictionary.txt" file doesn't open
        cerr << "cant find file";
    }

    // Menu
    cout << "Welcome to the word translator!\n\n";
    cout << "1. Translate from English to Spanish\n";
    cout << "2. Translate from Spanish to English\n\n";
    cout << "Enter your choice (1 or 2):";
    int choice;
    cin >> choice;

    if (choice != 1 && choice != 2) {
    // Returns error if the user does not input either "1" nor "2"
        cerr << "Invalid choice\n";
        return 0;
    }

    cout << "Enter the word to translate:";
    getline(cin >> ws, word);
    // Converts input to lowercase for easy handling
    for (int i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);


    if (choice == 1) {
        // Searches for inputted word in eng[] array
        for (int i = 0; i < wordNum; i++) {
            if (eng[i] == word) index = i;

        }
        // If the word is found in the eng[] database, the span[] index equivalent is output
        if (index >= 0) cout << "The Spanish word is: " << span[index] << endl;
    }
    else if (choice == 2) {
        // Searches for inputted word in the span[] array
        for (int i = 0; i < wordNum; i++) {
            if (span[i] == word) index = i;
        }
        // If the word is found in the span[] database, the eng[] index equivalent is output
        if (index >= 0) cout << "The English word is: " << eng[index] << endl;
    }

    // If inputted word does not match a word in the span[] database, an error message is returned
    if (index == -1) cerr << "Inputted word is not in the dictionary.\n";

    // Closes the "dictionary.txt" file
    dict.close();

    return 0;
}
