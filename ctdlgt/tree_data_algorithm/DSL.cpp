#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 1e9;
class DSU
{
    vector<int> parents;
    vector<int> ranks;
    int n;

public:
    DSU(int n)
    {
        this->n = n;
        parents.resize(n + 1, 0);
        ranks.resize(n + 1, 0);
        parents[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            parents[i] = i;
        }
    }
    inline int find_set(int u)
    {
        if (u == parents[u])
            return parents[u];
        return parents[u] = find_set(parents[u]);
    }
    void union_create(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if (u == v)
            return;
        if (ranks[u] < ranks[v])
            swap(u, v);
        parents[v] = u;
        if (ranks[u] == ranks[v])
        {
            ranks[u]++;
        }
    }
    friend ostream &operator<<(ostream &out, const DSU &output)
    {
        for (auto &i : output.parents)
        {
            out << i << " ";
        }
        return out;
    }
};
int main()
{
    DSU mytree(5);
    mytree.union_create(1, 4);
    mytree.union_create(4, 5);
    mytree.union_create(2, 3);
    mytree.union_create(3, 5);
    mytree.union_create(0, 3);
    mytree.union_create(3, 2);
    cout << mytree;
}