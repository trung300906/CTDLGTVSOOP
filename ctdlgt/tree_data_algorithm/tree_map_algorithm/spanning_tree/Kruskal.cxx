#include <bits/stdc++.h>
using namespace std;

class DSU
{
protected:
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dsu; // first is dis and second is root(first) to node(second)
    DSU(const int &node, const vector<vector<int>> &maps)
    {
        for (int i = 0; i < node; ++i)
        {
            for (int j = 0; j < node; ++j)
            {
                if (maps[i][j] > 0)
                {
                    dsu.push({maps[i][j], {i, j}});
                }
            }
        }
    }
};
class Kruskal : public DSU
{
private:
    vector<vector<int>> maps;
    vector<bool> mark;
    int node;

public:
    Kruskal() : DSU(node, maps)
    {
        cout << "input numbers of node: ";
        cin >> node;
        for (int i = 0; i < node; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < node; ++j)
            {
                int x;
                cout << "node from " << i << " to: " << j << " is: ";
                cin >> x;
                cout << endl;
                temp.push_back(x);
            }
            maps.push_back(temp);
            mark.push_back(false);
        }
    }
    void make_run()
    {
        int res = 0;
        while (!dsu.empty())
        {
            pair<int, pair<int, int>> temp = dsu.top();
            dsu.pop();
            if (mark[temp.second.first] && mark[temp.second.second])
            {
                continue;
            }
            mark[temp.second.first] = mark[temp.second.second] = true;
            res += temp.first;
        }
        cout << "result is: " << res << endl;
    }
};
int main()
{
}