#include <bits/stdc++.h>
using namespace std;
int countpath(vector<vector<bool>> &map, vector<pair<char, bool>> &path, int x = 0, int y = 0, int run = 0)
{
    int sum = 0;
    if (x < 0 || y < 0 || x >= map.size() || y >= map[0].size() || run < 0 || run >= path.size() || path[run].second == false || map[x][y] == false)
    {
        if (path[run - 1].second == true)
        {
            path[run - 1].second = false;
            sum++;
        }
        return sum;
    }
    map[x][y] = false;
    int movex[] = {-1, 1, 0, 0}, movey[] = {0, 0, -1, 1};
    char move[] = {'U', 'D', 'L', 'R'};
    for (int i = run; i < path.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (path[i].first == move[j])
            {
                sum += countpath(map, path, x + movex[j], y + movey[j], i + 1);
            }
        }
        map[x][y] = true;
        sum--;
    }
    return sum;
}
int main()
{
    int m, n, p, k;
    // cin >> m >> n >> p >> k;
    m = 5, n = 5, p = 2, k = 12;
    vector<vector<bool>> map(m, vector<bool>(n, true));
    vector<pair<char, bool>> path(k, {'0', true});

    for (int i = 1; i <= p; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x - 1][y - 1] = false;
    }

    string temp;
    // cin >> temp;
    temp = "RDDDDRRRRRUD";
    for (int i = 0; i < k; i++)
        path[i].first = temp[i];
    cout << countpath(map, path);
}