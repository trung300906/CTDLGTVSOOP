#include <bits/stdc++.h>
using namespace std;

struct case_test
{
    int n;
    deque<int> data;
    void sort()
    {
        std::sort(data.begin(), data.end());
    }
};

int solve(vector<case_test> &test)
{
    for (int i = 0; i < test.size(); i++)
    {
        int ans = 0;
        for (int j = 0; j < 2; j++)
        {
            if (test[i].data.empty())
                break;
            ans += (test[i].data.back() - test[i].data.front());
            test[i].data.pop_front();
            test[i].data.pop_back();
        }
        cout << ans << "\n";
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<case_test> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].n;
        for (int j = 0; j < a[i].n; j++)
        {
            int x;
            cin >> x;
            a[i].data.push_back(x);
        }
        a[i].sort();
    }
    solve(a);
}
