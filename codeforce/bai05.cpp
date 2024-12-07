#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    int count = 0;
    for (auto &i : a)
    {
        cin >> i;
    }
    int thre = a[k - 1];
    for (auto &i : a)
    {
        if (i >= thre)
            count++;
    }
    cout << count << endl;
    return 0;
}