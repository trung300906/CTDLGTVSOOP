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
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // first is dis and second is root(first) to node(second)
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
            int root = pq.top().second.first; // make previous dis
            int dis = pq.top().second.second; // make next dis
            if (root != dis)
                ans[root].push_back(dis);
            mark_node[root] = true;
            pq.pop();
            for (int i = 0; i < maps[dis].size(); ++i)
                if (!mark_node[i] && maps[dis][i] > 0)
                    pq.push({maps[dis][i], {dis, i}});
        }
    }
};
/*
    // 0 2 dis = 0  i = 2 => root = 0 & dis = 2
    // 0 1 dis = 0  i = 1 => root = 0 & dis = 1
    // 0 3 dis = 0  i = 3 => root = 0 & dis = 3
    //=====> choose dis = 2
    // 2 5 dis = 2  i = 5 => root = 2 & dis = 5
    // 2 4 dis = 2  i = 4 => root = 2 & dis = 4
    //=====> choose dis = 4
    // 4 1 dis = 4  i = 1 => root = 4 & dis = 1
    // 4 6 dis = 4  i = 6 => root = 4 & dis = 6
    //=====> choose dis = 1
    // nothing can set more, choose another from priority queue
    //=====> choose dis = 5
    // 5 3 dis = 5  i = 3 => root = 5 & dis = 3
    // 5 6 dis = 5  i = 6 => root = 5 & dis = 6
    // 5 7 dis = 5  i = 7 => root = 5 & dis = 7
*/
int main()
{
}