#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> cars;
    cars.push("volvo");
    cars.push("lamborghini");
    cars.push("hoyota");
    while (!cars.empty())
    {
        cout << cars.top() << " ";
        cars.pop();
    }
    // stack<string>::iterator itr = cars.begin(); //=> not support
}