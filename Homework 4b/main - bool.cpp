#include <iostream>
#include <iomanip>
using namespace std;

//Name: Evan Meyers
//UAID: 010955257

int counter = 0;

void PrintBoard(bool (&board)[5][5], int &x, int &y)
{
    //Gives me another copy of the board, so I can have consistent printing 
    //each time the user inputs a location without the board resetting
    bool boardPrint[5][5];


    if (board[x][y] == true) boardPrint[x][y] = true;
    else if (board[x][y] == false) boardPrint[x][y] = false;

    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++){
            if (boardPrint[a][b] == true) cout << setw(3) << "X";
            else if (boardPrint[a][b] == false) cout << setw(3) << "O";
            else cout << setw(3) << "-";

        }
        cout << endl;
    }


}

void ProcessSelection(bool (&board)[5][5], bool (&dupBoard)[5][5])
{
    int x, y;

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

    if (board[x][y] == true) {

        if (board[x][y] == true && dupBoard[x][y] == true) {
            cout << "Hit!\n";
            counter = counter + 1;
        } else cout << "Duplicate hit!\n";
        dupBoard[x][y] = false;
    }

    if (board[x][y] == false) {
        cout << "Miss!\n";

    }

    PrintBoard(board, x, y);
}



int main() {

    cout << "Name:\tEvan Meyers\n" << "UAID:\t010955257\n" << "--------------------------\n";

    bool board[5][5], dupBoard[5][5], hit = false;


    //Set a fresh board by setting all spaces to false
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            board[x][y] = false;
        }
    }

    //Deploys battleships to the board
    board[1][2] = true;
    board[4][1] = true;
    board[2][4] = true;
    board[3][3] = true;
    board[0][2] = true;

    //Theres probably a better way to keep track of this, but I'm
    //duplicating the previous array to keep track of duplicate hits
    dupBoard[1][2] = true;
    dupBoard[4][1] = true;
    dupBoard[2][4] = true;
    dupBoard[3][3] = true;
    dupBoard[0][2] = true;
    while (counter < 5) {
        ProcessSelection(board, dupBoard);
    }

    cout << "YOU WIN!\n";
    return 0;
}



