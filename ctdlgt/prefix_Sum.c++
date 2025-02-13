#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
#if 1
    vector<int> a;
    for (int i = 0; i < 1000; i++)
    {
        a.push_back(rand() % 1000 + 1);
    }
    vector<int> prefix_Sum(a.size(), 0);
    for (int i = 0; i <= prefix_Sum.size(); i++)
    {
        prefix_Sum[i] = prefix_Sum[i - 1] + a[i];
    }
    int x, y;
    cin >> x >> y;
    cout << "sum from " << x << " to " << y << " of a array is: " << abs(prefix_Sum[y] - prefix_Sum[x]);
#endif
#if 0
    vector<vector<int>> a;
    vector<int> temp;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            temp.push_back(rand() % 1000 + +1);
        }
        a.push_back(temp);
        temp.clear();
    }
    temp.shrink_to_fit();
    // int x, y;
    // cin >> x >> y;
    vector<vector<int>> s(1000, vector<int>(1000, 0));
    cout
        << sizeof(a);
    cout << sizeof(temp);
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            s[i][j] = a[i][j];
            if (i > 0)
                s[i][j] += s[i - 1][j];
            if (j > 0)
                s[i][j] += s[i][j - 1];
            if (i > 0 && j > 0)
                s[i][j] -= s[i - 1][j - 1];
        }
    }
#endif
    return 0;
}