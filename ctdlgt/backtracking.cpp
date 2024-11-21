#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1 + 1e5;

int n;
vector<vector<bool>> mark(3, vector<bool>(MaxN));
vector<int> res;

void Try(int row)
{
    if (row == n + 1)
    {
        for (int i = 0; i < n; ++i)
            cout << i + 1 << " " << res[i] << endl;
        exit(0);
        // Do chỉ cần in ra 1 đáp án nên ta sẽ thoát khỏi chương trình ngay tại đây.
        // Trên thực tế việc dùng hàm exit() tại đây là không tốt. Tuy nhiên, trong khuôn khổ của lập trình thi đấu, việc này là chấp nhận được.
    }
    for (int col = 1; col <= n; ++col)
    {
        // Do hiệu của chỉ số hàng và cột có thể âm nên ta cộng thêm n
        int mainDiagonal = row - col + n, subDiagonal = row + col;
        // mark[0][]: cột
        // mark[1][]: đường chéo chính
        // mark[2][]: đường chéo phụ
        if (mark[0][col] || mark[1][mainDiagonal] || mark[2][subDiagonal])
            continue;
        mark[0][col] = 1;
        mark[1][mainDiagonal] = 1;
        mark[2][subDiagonal] = 1;
        for (auto &i : mark)
        {
            for (int j = 0; j <= n*2; j++)
            {
                cout << i[j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        res.push_back(col);
        Try(row + 1);
        res.pop_back();
        mark[0][col] = 0;
        mark[1][mainDiagonal] = 0;
        mark[2][subDiagonal] = 0;
    }
}

int main()
{
    // freopen("CTDL.inp", "r", stdin);
    // freopen("CTDL.out", "w", stdout);
    n = 4;
    Try(1);

    return 0;
}