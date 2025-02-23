#include <bits/stdc++.h>
using namespace std;

class prim
{
private:
    vector<vector<int>> maps;
    priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq; // first is distance and second is boolean
    int node;

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
            pq.push(make_pair(false, INT_MAX));
        }
    }
};
int main()
{
}