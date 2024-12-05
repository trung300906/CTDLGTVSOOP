#include <bits/stdc++.h>
using namespace std;

int main()
{
    int probn;
    cin >> probn;
    vector<vector<int>> verdict(probn, vector<int>(3));
    for (int i = 0; i < probn; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> verdict[i][j];
        }
    }
    int counttong = 0;
    for (auto &i : verdict)
    {
        int count = 0;
        for (auto &j : i)
        {
            if (j == 1)
                count++;
        }
        if (count >= 2)
            counttong++;
    }
    cout << counttong;
    return 0;
}