#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

bool mark[MAX];
vector<int> store[MAX];

void bfs()
{
    queue<int> bfs;
    bfs.push(1);
    int u;
    while (!bfs.empty())
    {
        u = bfs.front();
        bfs.pop();
        mark[u] = 1;
        cout << u << " ";
        for (auto &i : store[u])
        {
            if (!mark[i])
                bfs.push(i);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int first, second;
        cin >> first >> second;
        store[first].push_back(second);
        store[second].push_back(first);
    }
    bfs();
}