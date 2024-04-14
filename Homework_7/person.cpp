#include "person.h"
#include <iostream>
using namespace std;

// Default constructor
person::person() {
    first = "N/A";
    last = "N/A";
    birth = 0;
    death = "N/A";
    age = 0;
    biography = "N/A";
}

person::person(string firstName, string lastName, int b, int d, int a, string bio) {
    first = firstName;
    last = lastName;
    birth = b;
    death = d;
    age = a;
    biography = bio;
}

// Copy constructor
person::person(const person &copy) {
    first = copy.first;
    last = copy.last;
    birth = copy.birth;
    death = copy.death;
    age = copy.age;
    biography = copy.biography;
}

// Destructor
person::~person() {
}


// ----------Getters----------- //

string person::getFirst() const{
    return first;
}

string person::getLast() const{
    return last;
}

void person::getAge() const{
    cout << age << endl;
}

int person::getBirth() const {
    return birth;
}

void person::getDeath() const {
    cout << death << endl;
}

void person::getBiography() const {
    cout << biography << endl;
}


// ----------Setters----------- //

void person::setFirst(string firstName) {

    first = firstName;
}

void person::setLast(string lastName) {

    last = lastName;
}

void person::setAge(int old) {

    age = old;
}

void person::setBirth(int year) {

    birth = year;
}

void person::setDeath(string year) {

    death = year;
}

void person::setBiography(string bio) {

    biography = bio;
}

// ---------------------------- //


// Print method
void person::print() const {
    cout << "-------------------------------------------------------------------------------------------------------------\n"
            "     Name:  " << first << " " << last <<  "\n Lifespan:  "
    << birth << " - " << death << "\n      Age:  " << age << "\nBiography:  " << biography << endl <<
    "-------------------------------------------------------------------------------------------------------------"
    << endl << endl;
}