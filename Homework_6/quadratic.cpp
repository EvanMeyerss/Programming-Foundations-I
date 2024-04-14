#include "quadratic.h"
#include <cctype>
#include <iostream>
#include <cmath>

using namespace std;

// Default polynomial
Quadratic::Quadratic() {
    A = 0;
    B = 0;
    C = 0;
}

// Defined polynomial
Quadratic::Quadratic(const int a, const int b, const int c) {
    A = a;
    B = b;
    C = c;
}

// Defined polynomial with function name
Quadratic::Quadratic(const int a, const int b, const int c, char name) {
    A = a;
    B = b;
    C = c;
    funcName = name;
}

// Copier polynomial function
Quadratic::Quadratic(const Quadratic &copy) {
    funcName = copy.funcName;
    A = copy.A;
    B = copy.B;
    C = copy.C;
}

//Destructor
Quadratic::~Quadratic()
{
    cout << "Destructing polynomial\n";
}

// Gets polynomial coefficients
int Quadratic::GetElement(char var) const{
    int num;

    // Lowercases the variable for better handling and error checking
    tolower(var);
    if (var == 'a') {
        num = A;
    }
    else if (var == 'b') {
        num = B;
    }
    else {
        num = C;
    }
    return num;
}

// Sets polynomial coefficients
void Quadratic::SetElement(char var, int num) {

    // Lowercases the variable for better handling and error checking
    tolower(var);
    if (var == 'a') {
        A = num;
    }
    else if (var == 'b') {
        B = num;
    }
    else {
        C = num;
    }
}

// Prints out polynomial
void Quadratic::Print() {

    // Checks if the polynomial was given a name
    if(funcName != NULL) {
        cout << funcName << "(x) = ";
    }

    cout << A << "x^2 ";
    if (B > 0) cout << "+ " << B << "x ";
    else cout << "- " << B << "x ";

    if (C > 0 ) cout << "+ " << C << endl;
    else cout << "- " << C << endl;
}

// Adds two polynomials
void Quadratic::Add(Quadratic &q1, Quadratic &q2) {

    int a1,a2,b1,b2,c1,c2, aSum, bSum, cSum;
    a1 = q1.GetElement('a');
    a2 = q2.GetElement('a');
    b1 = q1.GetElement('b');
    b2 = q2.GetElement('b');
    c1 = q1.GetElement('c');
    c2 = q2.GetElement('c');

    aSum = a1+a2;
    bSum = b1+b2;
    cSum = c1+c2;

    cout << "\nAdding...\n\t";
    q1.Print();
    cout << "        - \n\t";
    q2.Print();
    cout << "\t-----------------------\n\t\t";
    cout << aSum << "x^2";


    if (bSum > 0) cout << " + " << bSum << "x";
    else cout << " - " << abs(bSum) << "x";

    if (cSum > 0) cout << " + " << cSum;
    else cout << " - " << abs(cSum);
    cout << endl;
}

// Subtracts one polynomial from another
void Quadratic::Subtract(Quadratic &q1, Quadratic &q2) {

    int a1,a2,b1,b2,c1,c2, aDif, bDif, cDif;
    a1 = q1.GetElement('a');
    a2 = q2.GetElement('a');
    b1 = q1.GetElement('b');
    b2 = q2.GetElement('b');
    c1 = q1.GetElement('c');
    c2 = q2.GetElement('c');

    aDif = a1-a2;
    bDif = b1-b2;
    cDif = c1-c2;

    cout << "\nSubtracting...\n\t";
    q1.Print();
    cout << "        - \n\t";
    q2.Print();
    cout << "\t-----------------------\n\t\t";

    cout << aDif << "x^2";

    if (bDif > 0) cout << " + " << bDif << "x";
    else cout << " - " << abs(bDif) << "x";

    if (cDif > 0) cout << " + " << cDif;
    else cout << " - " << abs(cDif);


}

// Evaluates values of x in polynomial
int Quadratic::Evaluate(int x) {
    eval = A * pow(x, 2) + B * x + C;
    return eval;
}

// Finds derivative of polynomial
void Quadratic::Derive() {

    dA = A*2;
    // Checks if polynomial was given a name
    if(funcName != NULL) {
        cout << funcName << "'(x) = ";
    }
    if (A > 0) cout << dA << "x ";
    if (B > 0) cout << "+ " << B << endl;
    else cout << "- " << B << endl;
}

// Finds zeros of polynomial
void Quadratic::Zeros() {

    // Runs if function is linear
    if (A == 0) {
        zeroLinear = -C/B;
        cout << "The zero for the linear function is:\n\tx = " << zeroLinear << endl;
    }

    // Runs if function is quadratic
    if (A > 0) {
        // Discriminant calculation
        dis = ((B * B) - 4 * A * C);

        // Tests if discriminant is negative (will lead to imaginary numbers)
        if (dis < 0) {
            cout << "\nThe zeros of the polynomial are:\n\tx = " << B / (2 * A) << " + " << "sqrt(" << dis << ") / "
                 << 2 * A << "\n\tx = " << B / (2 * A) << " - " << "sqrt(" << dis << ") / " << 2 * A << endl;
        } else {
            zero1 = (-B + sqrt(abs(dis))) / (2 * A);
            zero2 = (-B - sqrt(abs(dis))) / (2 * A);
            cout << "The zeros of the polynomial are:\n\tx = " << zero1
                 << "\n\tx = " << zero2 << endl;
        }

    }
}