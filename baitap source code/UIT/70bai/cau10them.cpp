#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int max = 0;
    for (auto &i : a)
    {
        cin >> i;
        if (i > max && i > 0)
            max = i;
    }
    cout << max << endl;
    return 0;
}