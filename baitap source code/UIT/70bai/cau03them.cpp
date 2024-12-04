#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (auto &i : a)
    {
        if (i < 0)
            cout << i << " ";
    }
    return 0;
}