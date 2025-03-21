#include <bits/stdc++.h>
using namespace std;

struct test
{
    int n, k;
    vector<int> data;
    unordered_map<int, int> freq;
};
void solve(vector<test> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        int one = 0, two = 0;
        for (int j = 1; j <= a[i].n; j++)
        {
            if (a[i].freq[j] > 0)
            {
                one++;
                if (a[i].freq[j] >= 2)
                {
                    two++;
                }
            }
        }
        if (a[i].k <= one && one <= 2 * a[i].k && (2 * a[i].k - one <= two))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<test> a;
    for (int i = 0; i < n; i++)
    {
        test tmp;
        cin >> tmp.n >> tmp.k;
        for (int j = 0; j < tmp.n; j++)
        {
            int x;
            cin >> x;
            tmp.data.push_back(x);
            tmp.freq[x]++;
        }
        a.push_back(tmp);
    }
    solve(a);
}