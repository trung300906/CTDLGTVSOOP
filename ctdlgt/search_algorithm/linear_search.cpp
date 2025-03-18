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
    int k;
    cin >> k;
    auto it = find(a.begin(), a.end(), k);
    int count = 0;
    vector<pair<int, int>> ans;
    while (it != a.end())
    {
        ans.push_back({distance(a.begin(), it), distance(a.begin(), it) + 1});
        a[distance(a.begin(), it)] = INT_MAX;
        it = find(a.begin(), a.end(), k);
    }
    cout << ans.size() << "\n";
    if (ans.size() != 0)
    {
        for (auto &i : ans)
        {
            cout << i.first << " " << i.second << "\n";
        }
    }
}
