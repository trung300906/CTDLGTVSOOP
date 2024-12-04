#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &i : a)
        cin >> i;
    int max_val = *max_element(a, a + n);
    cout << max_val << endl;
    return 0;
}