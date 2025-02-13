#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> a = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1}}; // a tree using linear matrix
                          // create matrix 10x10
                          /*
                                      1-2-3-4-5-3-1-2
                                      if have linked -> 1 for this value and alternative
                          */
    // method 2: using edge pair to stored
    vector<pair<int, int>> b = {
        {1, 2},
        {1, 3},
        {2, 3},
        {3, 4},
        {3, 5},
        {4, 5}};

    // method 3: using Adjacency List
    vector<vector<int>> c;
    int n;
    for (int i = 0; i < 5; i++)
    {
        cout << "dinh so: " << i+1 << endl;
        cin >> n;
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            cin >> temp[i];
        }
        c.push_back(temp);
        temp.clear();
        temp.shrink_to_fit();
    }
}