#include<bits/stdc++.h>
using namespace std;
// bài này google gần như sạch sẽ, vì code kiểu nào cx segmentation fault vs illegal instruction :))
/* 
DFS (Depth-First Search) là một kỹ thuật trong lập trình và thuật toán dùng để duyệt và tìm kiếm các đỉnh (hoặc ô) trong đồ thị hoặc cây (graph hoặc tree). DFS là một phương pháp tìm kiếm dựa trên nguyên tắc "sâu trước" (thường sử dụng đệ quy) để duyệt qua tất cả các đỉnh của đồ thị.

Cách hoạt động của DFS:

Bắt đầu từ một đỉnh gốc (thường là đỉnh đầu tiên) hoặc một nút gốc.
Đánh dấu đỉnh này là đã thăm.
Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại (các đỉnh chưa được thăm) bằng cách gọi đệ quy hoặc sử dụng ngăn xếp (stack).
Khi không còn đỉnh kề nào để thăm, quay lại đỉnh trước đó và tiếp tục duyệt.
Lặp lại quá trình cho đến khi tất cả các đỉnh được thăm hoặc đủ điều kiện dừng.
DFS có nhiều ứng dụng trong lập trình và thuật toán, bao gồm:

Tìm kiếm đường đi trong đồ thị.
Xác định kết nối giữa các đỉnh hoặc thành phần liên thông.
Tìm kiếm các vòng trong đồ thị.
Giải quyết các bài toán như tìm kiếm bằng đệ quy.
DFS có thể được triển khai bằng đệ quy hoặc sử dụng một ngăn xếp (stack) để theo dõi các đỉnh chưa được thăm. Phương pháp duyệt DFS tùy theo cách triển khai có thể đệ quy hoặc không đệ quy.
 */
#define MAX 25
int n, m, a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], d[MAX][MAX], dx[2] = {0, 1}, dy[2] = {1, 0};
bool visited[MAX][MAX];
vector<pair<int, int>> path;

bool isInside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void DFS(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 2; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (isInside(u, v) && !visited[u][v] && a[u][v] != -1) {
            if (a[u][v] != 0) {
                if (b[x][y] == 0) {
                    b[u][v] = a[u][v];
                    c[u][v] = c[x][y] + 1;
                    d[u][v] = d[x][y];
                    DFS(u, v);
                } else if (a[u][v] != b[x][y]) {
                    b[u][v] = a[u][v];
                    c[u][v] = c[x][y] + 1;
                    d[u][v] = d[x][y] + 1;
                    DFS(u, v);
                } else {
                    b[u][v] = b[x][y];
                    c[u][v] = c[x][y] + 1;
                    d[u][v] = d[x][y];
                    DFS(u, v);
                }
            } else {
                b[u][v] = b[x][y];
                c[u][v] = c[x][y] + 1;
                d[u][v] = d[x][y];
                DFS(u, v);
            }
        }
    }
}

void trace(int x, int y) {
    if (x == 1 && y == 1) {
        path.push_back({1, 1});
        return;
    }
    for (int i = 0; i < 2; i++) {
        int u = x - dx[i];
        int v = y - dy[i];
        if (isInside(u, v) && c[u][v] + 1 == c[x][y] && d[u][v] == d[x][y]) {
            trace(u, v);
            break;
        }
    }
    path.push_back({x, y});
}

int main() {
    vector<vector<int>> store = {
        {5,1,2,3,-1,1},
        {1,1,2,-1,1,2},
        {1,1,2,-1,1,1},
        {1,-1,1,2,1,1},
        {1,2,1,1,-1,1},
        {1,1,1,2,1,5}
    };
    n = store.size();
    m = store[0].size();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = store[i-1][j-1];
    DFS(1, 1);
    if (d[n][m] < 2) cout << -1;
    else {
        cout << c[n][m] << '\n';
        trace(n, m);
        for (auto i : path) cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}