#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    // Declare array of integers
    const int DATA_SIZE = 20;
    int data[DATA_SIZE] = {0};

    // Print array
    for (int index = 0; index < DATA_SIZE; index++)
        cout << data[index] << " ";
    cout << endl;

    // Initialize array
    for (int index = 0; index < DATA_SIZE; index++)
        data[index] = random() % 100;

    // Print array
    for (int index = 0; index < DATA_SIZE; index++)
        cout << data[index] << " ";
    cout << endl;

    // Reverse array

    return 0 ;
}