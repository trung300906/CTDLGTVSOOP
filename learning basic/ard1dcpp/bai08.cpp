#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    while (find(a.begin(), a.end(), x) != a.end())
    {
        a.erase(find(a.begin(), a.end(), x));
    }
    for (auto &i : a)
        cout << i << " ";
    return 0;
}