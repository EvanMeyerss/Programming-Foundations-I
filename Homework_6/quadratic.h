#include <iostream>
using namespace std;

class Quadratic
{
public:
Quadratic();
Quadratic(int a, int b, int c);
Quadratic(int a, int b, int c, char name);
Quadratic(const Quadratic & copy);
~Quadratic();

int GetElement(char var) const;
void SetElement(char var, int num);
void Print();
void Add(Quadratic &q1, Quadratic &q2);
void Subtract(Quadratic &q1, Quadratic &q2);
int Evaluate(int x);
void Derive();
void Zeros();


private:
    int dA, A, B, C, eval;
    double dis, zero1, zero2, zeroLinear;
    string function, functionD;
    char funcName = NULL;

};