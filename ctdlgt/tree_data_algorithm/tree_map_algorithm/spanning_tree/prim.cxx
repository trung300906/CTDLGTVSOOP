#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};
class prim
{
private:
    vector<vector<int>> maps;                                                                                            // maps weight round for node e
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // first is dis and second is root to node
    vector<bool> mark_node;                                                                                              // for mark node visited
    int node;
    vector<int> ans[INT_MAX];

public:
    prim()
    {
        cin >> node;
        for (int i = 0; i < node; i++)
        {
            vector<int> temp;
            for (int j = 0; j < node; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            maps.push_back(temp);
            mark_node.push_back(false);
        }
    }
    void make_run()
    {
        pq.push(make_pair(0, make_pair(0, 0))); // dis 0 with node 0 to 0
        while (!pq.empty() && any_of(mark_node.begin(), mark_node.end(), [](const bool &since)
                                     { return !since; }))
        {
            int root = pq.top().second.first;
            int dis = pq.top().second.second;
            if (dis != root)
            {
                ans[root].push_back(dis);
                ans[dis].push_back(root);
            }
            mark_node[root] = true;
            pq.pop();
            for (int itr = 0; itr < maps[root].size(); ++itr)
            {
                pq.push({maps[root][itr], {root, itr}});
            }
        }
    }
};
int main()
{
}