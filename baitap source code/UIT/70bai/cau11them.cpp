#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &i : a)
        cin >> i;
    int index;
    cin >> index;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == index)
        {
            cout << i << endl;
            break;
        }
    }
}