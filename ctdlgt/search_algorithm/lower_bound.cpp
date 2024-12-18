#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), m);
    cout << * << endl;
}