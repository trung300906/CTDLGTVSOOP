#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = *max_element(a, a + n);
    cout << max << endl;
    int count = 0;
    for (auto &i : a)
    {
        if (i == max)
            count++;
    }
    cout << count;
    return 0;
}