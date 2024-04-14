//Include statements
#include <iostream><iomanip>
using namespace std;

/*
Author: Evan Meyers
    ID: 010955257
				________________
				| Author Notes |
				----------------

   I looked up how to bold text, so if you're confused
or suspicious as to why my titles for each shape have
the weird formatting, that's why. I saw that the
homework instructions document had the titles bolded
so I wanted to mimick it as close as possible.
*/


//Main function
int main()
{

	//Variables
	int size;
	bool valid = false;

	//Cin size
	cout << "Enter shape size (integer 1 - 20): ";
	cin >> size;

	//Ensures input is numeric
	while (cin.fail()) {
		cout << "\nInvalid input, try again.\n\n" << "Enter shape size (integer 1 - 20): ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> size;
	}

	//Ensures size input is between 5 and 20 inclusive
	while (!valid) {
		if (size >= 5 && size <= 20) valid = true;
		else if (cin.fail()) {
			cin.clear();
			cout << "\nInvalid input, try again.\n\n" << "Enter shape size (integer 1 - 20): ";
			cin >> size;
		}
		else {
			cout << "\nInvalid input, try again.\n\n" << "Enter shape size (integer 1 - 20): ";
			cin >> size;
		}

	}


	cout << endl; //----------------------------------------------------


	//Solid square shape
	cout << "\x1b[1mSolid Square Pattern\x1b[0m" << endl;
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			cout << "* ";
		}
		cout << endl;
	}


	cout << endl; //----------------------------------------------------


	//Square outline shape
	cout << "\x1b[1mSquare Outline Pattern\x1b[0m" << endl;
	for (int row = 0; row < size; row++)
	{
		if (row == 0 || row == size - 1)
		{
			for (int i = 0; i < size; i++)
			{
				cout << "* ";
			}
		}


		if (!(row == 0 || row == size - 1))
		{
			for (int col = 0; col < size; col++)
			{
				if (col == 0 || col == size - 2)
				{
					cout << "* ";
				}

				cout << "  ";

			}
		}
		cout << endl;
	}


	cout << endl; //----------------------------------------------------



	//Right triangle 
	//(I somehow did this second try and I will never doubt my abilities again lol)
	cout << "\x1b[1mSolid Triangle Pattern\x1b[0m" << endl;
	for (int row = 0; row <= size; row++)
	{
		for (int col = 0; col < row; col++)
		{
			cout << "* ";
		}
		cout << endl;
	}


	cout << endl; //----------------------------------------------------


	//X pattern
	cout << "\x1b[1mLetter X Pattern\x1b[0m" << endl;
	for (int row = 1; row <= size; row++)
	{
		for (int col = 1; col <= size; col++)
		{
			if ((col == row) || (col == (size + 1 - row))) cout << "* ";
			else cout << "  ";
		}

		cout << endl;
	}


	cout << endl; //----------------------------------------------------


	//Z pattern
	//This sucked, i hated it a lot
	cout << "\x1b[1mLetter Z Pattern\x1b[0m" << endl;
	for (int row = 0; row < size; row++)
	{
			for (int col = 0; col < size; col++)
			{
				if ((row == 0) || (row + col == size - 1) || (row == size - 1)) cout << "* ";
				else cout << "  ";
			}
			cout << endl;	
	}



	return 0;
}