#include <bits/stdc++.h>
using namespace std;

class loang_algo
{
private:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<vector<pair<bool, int>>> maps; // first for mark and second for value
    vector<int> ans;
    int rows, collom;
    // private member function
    int loang(int x, int y)
    {
        int res = 0;
        queue<pair<int, int>> que; // first for x, second is for y
        que.push({x, y});
        maps[x][y].second = true;
        while (!que.empty())
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            res++;
            for (int i = 0; i < 4; i++)
            {
                if ((x + dx[i] > 0 && x + dx[i] < collom) && (y + dy[i] > 0 && y + dy[i] < rows) && maps[x + dx[i]][y + dy[i]].first == 1 && !maps[x + dx[i]][y + dy[i]].second)
                {
                    que.push({x + dx[i], y + dy[i]});
                    maps[x + dx[i]][y + dy[i]].second = true;
                }
            }
        }
        return res;
    }

public:
    loang_algo()
    {
        cin >> rows >> collom;
        for (int i = 0; i < rows; i++)
        {
            vector<pair<bool, int>> temp;
            for (int j = 0; j < collom; j++)
            {
                int x;
                cin >> x;
                temp.push_back(make_pair(x, false));
            }
            maps.push_back(temp);
        }
    }
    void make_run()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < collom; j++)
            {
                if (maps[i][j].first == 1 && !maps[i][j].second)
                    ans.push_back(loang(i, j));
            }
        }
        sort(ans.begin(), ans.end());
    }
    friend ostream &operator<<(ostream &out, loang_algo output)
    {
        for (auto &i : output.ans)
        {
            out << i << " ";
        }
        return out;
    }
};
int main()
{
}