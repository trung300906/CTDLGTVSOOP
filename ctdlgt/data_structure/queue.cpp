#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> cars;
    cars.push("volvo");
    cars.push("lamborghini");
    cars.push("ferari");
    while (!cars.empty())
    {
        cout << cars.front() << " ";
        cars.pop();
    }
    // queue<string>::iterator itr = cars.begin(); => not support
}