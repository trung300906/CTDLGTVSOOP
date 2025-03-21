#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> seen;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i <= n; i++)
    {
        pq.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        seen.insert(a[i]);
        while (!pq.empty() && seen.count(pq.top()))
            pq.pop();
        cout << pq.top() << " ";
    }
}