#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 1e6;
bool mark[MAXINT];
vector<int> store[MAXINT];
int n;

void dfs(int &u)
{
    cout << u << " ";
    mark[u] = 1;
    for (auto &v : store[u])
        if (!mark[v])
            dfs(v);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int fir, sec;
        cin >> fir >> sec;
        store[fir].push_back(sec);
        store[sec].push_back(fir);
    }
    int u = 1;
    dfs(u);
}