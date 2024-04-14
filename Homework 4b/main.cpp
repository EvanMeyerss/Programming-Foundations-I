#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

//Name: Evan Meyers
//UAID: 010955257

int sunk = 0, boardPrint[5][5], round = 0;

//Function that allows the user to quit
void quit() {

    //Another board that prints the correct hits
    int forfeitBoard[5][5];
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            forfeitBoard[y][x] = 1;
        }
    }

    forfeitBoard[1][2] = 0;
    forfeitBoard[4][1] = 0;
    forfeitBoard[2][4] = 0;
    forfeitBoard[3][3] = 0;
    forfeitBoard[0][2] = 0;

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++){
            if (forfeitBoard[y][x] == 0) cout << setw(3) << "X";
            else if (forfeitBoard[y][x] == 1) cout << setw(3) << "-";
        }
        cout << endl;
    }
    cout << "You played " << round << " round(s).\n" << "Better luck next time.\n";

}

int PrintBoard(int (&board)[5][5], int &x, int &y)
{


         if (board[y][x] == 0) boardPrint[y][x] = 0;
    else if (board[y][x] == 1) boardPrint[y][x] = 1;
    else if (board[y][x] == 2) boardPrint[y][x] = 2;

    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++){
            if (boardPrint[a][b] == 0) cout << setw(3) << "X";
            else if (boardPrint[a][b] == 1) cout << setw(3) << "O";
            else if (boardPrint[a][b] == 2) cout << setw(3) << "-";

        }
        cout << endl;
    }

    return boardPrint[5][5];

}

void ProcessSelection(int (&board)[5][5], int (&dupBoard)[5][5])
{
    int x, y;
    string forfeit;

    //Forfeit
    if (round > 0) {
        cout << "Do you want to quit? (Yes or No)\n";
        getline(cin >> ws, forfeit);
        for (int i = 0; i < forfeit.length(); i++)
            forfeit[i] = tolower(forfeit[i]);
        if (forfeit == "yes") {
            quit();
            exit(0);
        }
    }

    //Assigns x-coordinate
    cout << "Input x-coordinate (0-4):\n";
    cin >> x;


    //Error checking for x-coordinate
    while ((cin.fail()) || (x < 0 || x > 4)) {
    cout << "Invalid input, try again: \n";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> x;
    }

    //Assigns y-coordinate
    cout << "Input y-coordinate (0-4):\n";
    cin >> y;
    //Error checking for x-coordinate
    while ((cin.fail()) || (y < 0 || y > 4)) {
        cout << "Invalid input, try again: \n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> y;
    }

    if (board[y][x] == 0) {

        if (board[y][x] == 0 && dupBoard[y][x] == 0) {
            cout << "Hit!\n";
            sunk = sunk + 1;
        } else cout << "Duplicate hit!\n";
        dupBoard[y][x] = 1;
    }

    if (board[y][x] == 1) {
        cout << "Miss!\n";

    }

    PrintBoard(board, x, y);
    round += 1;
}

int main() {

    cout << "---------------------------\n" <<"Name:\tEvan Meyers\n" << "UAID:\t010955257\n" << "---------------------------\n";

    int board[5][5], dupBoard[5][5], hit = 1;


    //Set a fresh board by setting all spaces to 1
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            board[y][x] = 1;
        }
    }

    //Deploys battleships to the board
    board[1][2] = 0;
    board[4][1] = 0;
    board[2][4] = 0;
    board[3][3] = 0;
    board[0][2] = 0;

    //Theres probably a better way to keep track of this, but I'm
    //duplicating the previous array to keep track of duplicate hits
    dupBoard[1][2] = 0;
    dupBoard[4][1] = 0;
    dupBoard[2][4] = 0;
    dupBoard[3][3] = 0;
    dupBoard[0][2] = 0;

    //Gives me another copy of the board, so I can have consistent printing
    //each time the user inputs a location without the board resetting
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            boardPrint[y][x] = 2;
        }
    }

    while (sunk < 5) {
        ProcessSelection(board, dupBoard);
    }

    if (sunk == 5) cout << "----------------------\n" << "|YOU WON IN " << round << " ROUNDS!|\n" << "----------------------\n";


    return 0;
}



