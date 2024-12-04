#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &i : a)
        cin >> i;
    for (const auto &i : a)
    {
        if (i % 2 != 0)
            cout << i << " ";
    }
}