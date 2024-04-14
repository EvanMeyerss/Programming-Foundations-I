//Include statements
#include <iostream> 
#include <cctype> 
#include <cmath> 
#include <string>
using namespace std;

// Author:	Evan Meyers
// ID:		010955257


//Payment type function
void paymentInfo(string &payment, int &tCost)
{
	float bill, change;
	int dollars, quarters, dimes, nickels, pennies;

	//Determines total cost and change for cash-paying customers
	if (payment == "cash")
	{
		cout << "\n-----------------------\n"
			 << "The total cost is $" << tCost << ".\n"
			 << "Input cash payment:\n"
			 << "-----------------------\n";
		
		cin >> bill;
		while (cin.fail())
		{
			cout << "Invalid input, try again: \n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> bill;
		}

		while (!(bill >= tCost))
		{
			cout << "Insufficient funds. Try again:\n";
			cin >> bill;
			while (cin.fail())
			{
				cout << "Invalid input, try again: \n";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> bill;
			}
		}
		
		//Calculates change 
		change = bill - tCost;

		if (change == 0) {
			cout << "\n-------------------------------\n"
				 << "You have no change.\n"
				 << "Thank you for shopping with us!\n"
				 << "-------------------------------\n";
		}

		else
		{
			dollars = (int)change;
			change = change - dollars;

			quarters = change / .25;
			change = change - quarters * .25;

			dimes = change / .10;
			change = change - dimes * .10;

			nickels = change / .05;
			change = change - nickels * .05;

			pennies = change / 0.01;


			//Output change amount
			cout << "\n------------------------------------------------------------------------\n"
				<< "Your change is " << dollars << " dollars, "
				<< quarters << " quarters, "
				<< dimes << " dimes, "
				<< nickels << " nickels, and "
				<< pennies << " pennies.\n"
				<< "Thank you for shopping with us!\n"
				<< "------------------------------------------------------------------------\n";
		}
	}


	else
	{
		//Tell credit card paying customers their total cost and that they will be charged
		cout << "\n--------------------------------\n"
			 << "The total cost is $" << tCost << ".\n"
			 << "Your credit card will be billed.\n"
			 << "Thank you for shopping with us!\n"
			 << "--------------------------------\n";
	}
	
}

//Calculates total price of ticket(s)
void ticketInfo(string &payment, string &tType, int &tNum)
{
	int tCost;

	if (tType == "nosebleed") tCost = tNum * 5;
	if (tType == "student section") tCost = tNum * 10;
	if (tType == "fifty yard line") tCost = tNum * 50;
	if (tType == "box seats") tCost = tNum * 100;
	
	paymentInfo(payment, tCost);
}


//Main function
int main() 
{
	string tType, payment;
	int tNum;

	cout << "-------------------\n"
		 << "Name:\tEvan Meyers\n"
		 << "UAID:\t010955257\n"
		 << "-------------------\n";
	
	cout << "\n------------------------------------\n"
		 << "Input payment type (Cash or Credit):\n" 
		 << "------------------------------------\n";


	//Converts input to lowercase for easy handling
	getline(cin, payment);
	for (int i = 0; i < payment.length(); i++)
		payment[i] = tolower(payment[i]);
	
	//Checks for valid payment input
	while (!(payment == "cash" || payment == "credit"))
	{
		cout << "Invalid input, try again: \n";
		getline(cin, payment);
		for (int i = 0; i < payment.length(); i++)
			payment[i] = tolower(payment[i]);
	}

	cout << endl;

	//------------------------------------------------

	cout << "\n------------------------\n"
		<< "Select ticket type:\n"
		<< "------------------------\n"
		<< "Nosebleed\t- $5\n"
		<< "Student Section\t- $10\n"
		<< "Fifty Yard Line\t- $50\n"
		<< "Box Seats\t- $100\n"
		<< "------------------------\n";

	//Converts input to lowercase for easy handling
	getline(cin, tType);
	for (int i = 0; i < tType.length(); i++)
		tType[i] = tolower(tType[i]);

	//Checks for invalid tType input
	while (!(tType == "nosebleed" || tType == "student section" || tType == "fifty yard line" || tType == "box seats"))
	{
		cout << "Invalid input, try again: \n";
		getline(cin, tType);
		for (int i = 0; i < tType.length(); i++)
			tType[i] = tolower(tType[i]);
	}

	//------------------------------------------------

	//Ticket number
	cout << "\n\n-----------------------------\n" 
		 << "How many tickets do you want?\n"
		 << "-----------------------------\n";
	cin >> tNum;
	
	//Checks for valid tNum input
	while (cin.fail())
	{
		cout << "Invalid input, try again: \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> tNum;
	}
	
	ticketInfo(payment, tType, tNum);

	return 0;
}