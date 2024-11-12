#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, dem = 0;
    cin >> n >> m;
    vector<int> nam(n);
    vector<int> nu(m);
    for (auto &i : nam)
        cin >> i;
    for (auto &i : nu)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nam[i] > nu[j])
                dem++;
            nu.erase(nu.begin() + j);
            break;
        }
    }
    cout << dem;
}