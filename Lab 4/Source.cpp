#include <iostream>
using namespace std;
int main()
{
    // Declare and initialize variables
    float InputValue = 0;
    float TotalValue = 0;
    float CountValue = 0;

    // Read input value
    cout << "Enter input value (or -1 to stop):\n";
    cin >> InputValue;

    // While loop to total up the daily sales
    while (InputValue != -1)
    {
        // Update total and count (FIX)
        TotalValue = TotalValue + InputValue;
        CountValue += 1;
        // Read input value
        cout << "Enter input value (or -1 to stop):\n";
        cin >> InputValue;
    }

    // Calculate and print average value (FIX)
    if (CountValue > 0) {
        float AverageValue = 0;
        AverageValue = TotalValue / CountValue;
        cout << "Average: " << AverageValue << endl;
    }
    return 0;
}