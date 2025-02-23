#include <bits/stdc++.h>
using namespace std;

class Dijkstra
{
private:
    const int INTMAX = 1e9;
    vector<vector<int>> maps; // duyet do
    vector<pair<bool, int>> check;
    int node, root;
    bool checkmap(const vector<pair<bool, int>> &check)
    {
        for (auto &i : check)
        {
            if (i.first == false)
                return false;
        }
        return true;
    }

public:
    Dijkstra()
    {
        cout << "build maps...";
        cin >> node;
        for (int i = 0; i < node; i++)
        {
            vector<int> temp;
            for (int j = 0; j < node; j++)
            {
                if (i == j)
                {
                    temp.push_back(0);
                    continue;
                }
                cout << "distance from node(-1 if not exist): " << i << " to: " << j << ": ";
                int x;
                cin >> x;
                temp.push_back(x);
            }
            maps.push_back(temp);
        }
        cout << endl
             << "nhap node khoi nguyen...(root node) ";
        cin >> root;
        for (int i = 0; i < node; i++)
        {
            check.push_back(make_pair(false, INTMAX));
        }
    }
    void make_run()
    {
        check[root].second = 0;
        while (any_of(check.begin(), check.end(), [](const pair<bool, int> &temp)
                      { return !temp.first; }))
        {
            check[root].first = true;
            pair<int, int> minode; // first is node second is value
            minode.first = root;
            minode.second = INTMAX;
            for (int i = 0; i < maps[root].size(); i++)
            {
                if (maps[root][i] > 0 && check[i].first == false)
                {
                    check[i].second = min(maps[root][i] + check[root].second, check[i].second);
                    if (minode.second > check[i].second)
                    {
                        minode.second = check[i].second;
                        minode.first = i;
                    }
                }
            }
            root = minode.first;
            if (minode.second == INTMAX)
                break;
        }
    }
    friend ostream &operator<<(ostream &out, Dijkstra output)
    {
        for (auto &i : output.check)
        {
            out << i.second << " ";
        }
        return out;
    }
};
int main()
{
}