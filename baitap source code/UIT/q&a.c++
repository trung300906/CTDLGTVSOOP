#include <iostream>

using namespace std;

int main()
{
    int temperature;

    // Input
    cout << "What is the outdoor temperature?" << endl;
    cin >> temperature;

    cout << "What is your plan today?" << endl;

    // Determine the plan based on the temperature
    if (temperature >= 33)
    {
        cout << "Good day for swimming" << endl;
    }
    else if (temperature >= 24 && temperature < 33)
    {
        cout << "Good day for golfing" << endl;
    }
    else if (temperature >= 10 && temperature < 24)
    {
        cout << "Good day to play tennis" << endl;
    }
    else
    {
        cout << "Go to bed" << endl;
    }

    return 0;
}
