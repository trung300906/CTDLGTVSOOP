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
    int indexbegin;
    cin >> indexbegin;
    int numdelete;
    cin >> numdelete;
    a.erase(a.begin() + indexbegin, a.begin() + indexbegin + numdelete);
    for (auto &i : a)
    {
        cout << i << " ";
    }
    return 0;
}