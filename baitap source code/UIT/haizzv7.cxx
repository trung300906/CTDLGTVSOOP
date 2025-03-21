#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<ll> a, b;

// Hàm mô phỏng cho giá trị H: nếu thành công, lưu các cặp (i, j)
// với i: chỉ số tấm hàng rào cần gia cố, j: chỉ số tấm gỗ dùng để gia cố.
bool check(ll H, vector<pair<int, int>> &used)
{
    used.clear();
    int j = 0; // chỉ số cho mảng b (0-indexed)
    for (int i = 0; i < n; i++)
    {
        if (a[i] < H)
        {
            ll need = H - a[i]; // cần tấm gỗ có chiều cao >= need
            // Loại các tấm không đủ chiều cao
            while (j < m && b[j] < need)
                j++;
            if (j == m)
                return false;               // không còn tấm phù hợp
            used.push_back({i + 1, j + 1}); // lưu theo chỉ số 1-indexed
            j++;                            // tấm đã dùng, chuyển sang tấm tiếp theo
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Đọc dữ liệu
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    b.resize(m);
    for (int j = 0; j < m; j++)
        cin >> b[j];

    // Xác định giới hạn tìm kiếm cho H:
    // H tối thiểu là min(a), và tối đa là max(a) + max(b)
    ll lo = *min_element(a.begin(), a.end());
    ll hi = *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end());
    ll ans = lo;
    vector<pair<int, int>> bestUsed;

    // Tìm kiếm nhị phân giá trị H khả thi cao nhất
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        vector<pair<int, int>> used;
        if (check(mid, used))
        { // nếu H = mid khả thi
            ans = mid;
            bestUsed = used; // lưu lại phương án hiện tại
            lo = mid + 1;    // thử nâng cao H
        }
        else
        {
            hi = mid - 1;
        }
    }

    // In kết quả: H tối đa và số tấm gỗ đã gia cố,
    // sau đó liệt kê các cặp (tấm hàng rào, tấm gỗ dùng)
    cout << ans << " " << bestUsed.size() << "\n";
    for (auto &p : bestUsed)
        cout << p.first << " " << p.second << "\n";
    return 0;
}
