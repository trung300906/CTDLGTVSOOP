#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row1, col1;
    cin >> row1 >> col1;
    vector<vector<float>> a(row1, vector<float>(col1));
    for (auto &i : a)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
    int row2, col2;
    cin >> row2 >> col2;
    if (row2 != col1)
        return 0;
    vector<vector<float>> b(row2, vector<float>(col2));
    for (auto &i : b)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
    vector<vector<float>> ans(row1, vector<float>(col2));
    // calculate a*b
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    //cout << "ans" << endl;
    for (auto &i : ans)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}