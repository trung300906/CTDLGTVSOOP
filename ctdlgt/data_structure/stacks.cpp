#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> cars;
    cars.push(5);
    cars.push(3);
    cars.push(10);
    while (!cars.empty())
    {
        cout << cars.top() << " ";
        cars.pop();
    }
    // stack<string>::iterator itr = cars.begin(); //=> not support
}