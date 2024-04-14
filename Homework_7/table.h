#include <iostream>
#include "person.h"

using namespace std;

    class table {


    public:
        table();
        table(const table & copy);
        ~table();

        void print();
        void read(const string& file);
        void firstSearch(const string& firstName);
        void lastSearch(const string& lastName);
        void yearSearch(int yearStart, int yearEnd);


    private:
        static const int NUM_PEOPLE = 20;
        person Person[NUM_PEOPLE];
        string tab[20], tempStr, deathStr = "Now";
        int tempNum1, tempNum2, tempAge;
    };

