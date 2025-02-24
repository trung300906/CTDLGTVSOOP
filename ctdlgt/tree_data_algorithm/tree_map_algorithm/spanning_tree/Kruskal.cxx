#include <bits/stdc++.h>>
using namespace std;

class Kruskal
{
private:
    vectot<vector<int>> maps;
    int node;
    vector<pair<int, pair<int, int>>> dsu;

public:
    Kruskal()
    {
        cou << "input numbers of node: ";
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
        }
    }
    void
};
int main()
{
}