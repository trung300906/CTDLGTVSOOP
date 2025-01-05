#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> store(h, vector<int>(w));
    auto min = INT_MAX;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> store[i][j];
            if (store[i][j] < min)
                min = store[i][j];
        }
    }
    int count = 0;
    for (const auto &i : store)
    {
        for (const auto &j : i)
        {
            if (j > min)
                count += j - min;
        }
    }
    cout << count;
    return 0;
}