#include <iostream>
using namespace std;

class person
{

public:

    // Constructors/Destructor
    person();
    person(string firstName, string lastName, int b, int d, int a, string bio);
    person(const person & copy);
    ~person();

    // Getters
    string getFirst() const;
    string getLast() const;
    void getAge() const;
    int getBirth() const;
    void getDeath() const;
    void getBiography() const;

    // Setters
    void setFirst(string firstName);
    void setLast(string lastName);
    void setAge(int old);
    void setBirth(int year);
    void setDeath(string year);
    void setBiography(string bio);

    // Print method
    void print() const;

private:
    string first, last, death, biography;
    int age, birth;
};