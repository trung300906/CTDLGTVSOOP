#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> numbers;
    for (int i = 0; i < 10; i++)
    {
        numbers.push_back(i * 2);
    }
    list<int>::iterator itr = numbers.begin();
    itr++;
    cout << *itr << endl;
    for (auto &i : numbers)
    {
        cout << i << " ";
    }
    cout << endl;
    // add element at the beginning
    numbers.push_front(0);

    // add element at the end
    numbers.push_back(4);
    for (auto &i : numbers)
    {
        cout << i << " ";
    }
    // display the first element
    cout << "\n First Element: " << numbers.front() << endl;

    // display the last element
    cout << "Last Element: " << numbers.back();
}