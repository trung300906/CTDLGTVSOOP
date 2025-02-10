#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    deque<string> cars;
    cars.push_back("volvo");
    cars.push_back("lamborghini");
    cars.push_back("ferari");
    deque<string>::iterator itr = cars.begin();
    itr++;
    cout << *itr << endl;
    for (auto &i : cars)
    {
        cout << i << " ";
    }
}