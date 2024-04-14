#include <iostream>
#include "quadratic.h"

using namespace std;

int main() {
    int A, B, C,
        x1,x2,x3,
        A2,B2,C2;
    char name, name2;

    cout << "-------------------\n"
         << "Name:\tEvan Meyers\n"
         << "UAID:\t010955257\n"
         << "-------------------\n";

    // Ask user for variables of quadratic
    cout << "Enter function name (ex. \"f,\" \"g,\" etc...)\n";
    cin >> name;
    while (cin.fail() || isdigit(name))
    {
        cout << "Invalid input, try again: \n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> name;
        tolower(name);
    }

    cout << "Enter three values for A, B, C:\n";
    cin >> A >> B >> C;

    // Variable error checking
    while (cin.fail())
    {
        cout << "Invalid input, try again: \n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> A >> B >> C;
    }

    // Construct quadratic 1
    Quadratic poly1(A, B, C, name);
    cout << endl;

    // Print quadratic
    poly1.Print();

    // Find zeros of quadratic
    poly1.Zeros();

    cout << "\nEnter three x-values to solve the quadratic equation with:\n";
    cin >> x1 >> x2 >> x3;

    // Variable error checking
    while (cin.fail())
    {
        cout << "Invalid input, try again: \n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> x1 >> x2 >> x3;
    }

    // Evaluates at the three inputted values of x

    cout << "The calculated x-values are:\n" <<  "\tx = " << x1 << ":\t" << poly1.Evaluate(x1) << endl << "\tx = " << x2 << ":\t"
         << poly1.Evaluate(x2) << endl << "\tx = " << x3 << ":\t" <<poly1.Evaluate(x3) << endl;

    cout << "\nThe derivative of the polynomial is:\n\t";
    poly1.Derive();

    cout << "\n------------------------------------------------------\n\n";

    cout << "Copying the polynomial \"poly1\" to \"poly2\"...\n\t";
    Quadratic poly2(poly1);
    poly2.Print();

    cout << "\nSetting A-value to equal \"-11\"...\n\t";
    poly2.SetElement('a', -11);
    poly2.Print();

    // Zeros of poly2
    poly2.Zeros();

    cout << "The calculated x-values are:\n" <<  "\tx = 3" << ":\t" << poly2.Evaluate(3) << endl << "\tx = 2" << ":\t"
         << poly2.Evaluate(2) << endl << "\tx = 5" << ":\t" <<poly2.Evaluate(5) << endl;


    cout << "\nThe derivative of the function is...\n\t";
    poly2.Derive();

    cout << "\n------------------------------------------------------\n\n";

    cout << "Creating a polynomial of degree 1 (linear)...\n\t";
    Quadratic poly3(0,2,4);
    poly3.Print();
    cout << endl;
    poly3.Zeros();
    cout << endl;

    cout << "The calculated x-values are:\n" <<  "\tx = 3" << ":\t" << poly3.Evaluate(3) << endl << "\tx = 2" << ":\t"
         << poly3.Evaluate(2) << endl << "\tx = 5" << ":\t" <<poly3.Evaluate(5) << endl;

    cout << "\nThe derivative of the function is...\n\t";
    poly3.Derive();


    cout << "\n------------------------------------------------------\n\n";

    cout << "Enter a quadratic to subtract from and add to f(x):\n";
    // Ask user for variables of quadratic
    cout << "Enter function name (ex. \"f,\" \"g,\" etc...)\n";
    cin >> name2;
    while (cin.fail() || isdigit(name2))
    {
        cout << "Invalid input, try again: \n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> name2;
        tolower(name2);
    }

    // Coefficients for new polynomial
    cout << "Enter three values for A, B, C:\n";
    cin >> A2 >> B2 >> C2;

    // Variable error checking
    while (cin.fail())
    {
        cout << "Invalid input, try again: \n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> A2 >> B2 >> C2;
    }

    // Creates new polynomial to do calculations with
    Quadratic poly4(A2,B2, C2, name2);


    //Subtracts the polynomials
    poly1.Subtract(poly1,poly4);

    cout << endl << endl;

    // Adds the polynomials
    poly1.Add(poly1, poly4);


    return 0;
}
