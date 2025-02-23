#include <bits/stdc++.h>
using namespace std;

class fenwick_tree
{
    vector<int> fenwick;
    int n;

public:
    fenwick_tree(int size)
    {
        n = size;
        fenwick.assign(n + 1, 0); // ngua overflow
    }
    void update(int i, int value)
    {
        for (; i <= n; i += i & -i)
            fenwick[i] += value;
    }
    int query(int idx)
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += fenwick[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    int query_range(int left, int right)
    {
        return query(right) - query(left);
    }
};
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 5, 6, 6};
    fenwick_tree mytree(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        mytree.update(i + 1, a[i]);
    }
    cout << mytree.query(5);
}