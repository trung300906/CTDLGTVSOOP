#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> job(n);
    for (auto &i : job)
        cin >> i;
    sort(job.begin(), job.end(), [](auto &a, auto &b)
         { return a > b; });
    vector<long long> ans(m, 0);
    auto it = min_element(ans.begin(), ans.end());
    for (auto &i : job)
    {
        ans[it - ans.begin()] += i;
        it = min_element(ans.begin(), ans.end());
    }
    auto maxit = max_element(ans.begin(), ans.end());
    cout << *maxit;
}