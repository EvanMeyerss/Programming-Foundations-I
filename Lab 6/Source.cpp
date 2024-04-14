#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int count = 100;
    int range = 100;
    int value = 42;
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        int num = random() % range;
        cout << num << " ";
    }
    cout << "\nthe value " << value
        << " was found " << found << " times\n";
    return 0;
}