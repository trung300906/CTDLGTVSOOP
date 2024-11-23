#include <bits/stdc++.h>
using namespace std;

vector<int> selection_sort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        auto min_idx = min_element(v.begin() + i, v.end());
        int min_pos = distance(v.begin(), min_idx);
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    selection_sort(v);
    for (auto &i : v)
        cout << i << endl;
}