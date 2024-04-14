//Include statements
#include <iostream>
using namespace std;


//Author creds
//Name: Evan Meyers
//  ID: 010955257


//Main function
int main() {

	//Variables
	int drinkType;
	string drinkSize;

	//-----------------------------------------------------------------

	//Beverage menu
	cout << "Coke \t\t(1):\t20oz - $1.50   or   2 liter - $1.75\n" <<
			"Pepsi \t\t(2):\t20oz - $1.00   or   2 liter - $2.00\n" <<
			"Mt. Dew \t(3):\t20oz - $0.75   or   2 liter - $1.90\n" <<
			"Dr. Pepper \t(4):\t20oz - $1.25   or   2 liter - $2.25\n";

	//-----------------------------------------------------------------

	// --Drink type--
	cout << "Choose soda type (1,2,3, or 4): ";
	cin >> drinkType;

	//I had to look up the "cin.fail()", "cin.clear()" and "cin.ignore(256, '\n')" 
	//because any string input into the drinkType variable would bring my code to its knees
	//-----------------------------------------------------------------
	//I used while loops instead of if-statements bc they are better in this case bc they 
	//will apply until the condition is true
	while (cin.fail()) {
		cout << "Invalid input, try again: " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> drinkType;

	}
	while (!(drinkType == 1 || drinkType == 2 || drinkType == 3 || drinkType == 4)) {
		cout << "Invalid input, try again: " << endl;
		cin >> drinkType;
	}

	//-----------------------------------------------------------------

	// --Drink size--
	//After finishing the program, I now realize that I should've just used "tolower()" function 
	//to convert the user input into lower case to shorten the condition statements for the if and switch statements
	cout << "Choose soda size (B - 20oz bottle, L - 2 liter bottle): ";
	cin >> drinkSize;

	while (!(drinkSize == "B" || drinkSize == "b" || drinkSize == "L" || drinkSize == "l")) {
		cout << "Invalid input, try again: ";
		cin >> drinkSize;
	}

	//-----------------------------------------------------------------

	//New line to make things look better when the total price is displayed
	cout << endl;

	//-----------------------------------------------------------------

	//Switch statements and if statements to display total price to user
	switch (drinkType) {
	case 1:
		if (drinkSize == "b" || drinkSize == "B") {
			cout << "Your total is: $1.50\n";
		}
		else {
			cout << "Your total is: $1.75\n";
		}
		break;

	case 2:
		if (drinkSize == "b" || drinkSize == "B") {
			cout << "Your total is: $1.00\n";
		}
		else {
			cout << "Your total is: $2.00\n";
		}
		break;

	case 3:
		if (drinkSize == "b" || drinkSize == "B") {
			cout << "Your total is: $0.75\n";
		}
		else {
			cout << "Your total is: $1.90\n";
		}
		break;

	case 4:
		if (drinkSize == "b" || drinkSize == "B") {
			cout << "Your total is: $1.25\n";
		}
		else {
			cout << "Your total is: $2.25\n";
		}
		break;

		
	}
	
	//-----------------------------------------------------------------

	return 0;
}