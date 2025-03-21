#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm kiểm tra xem với giới hạn maxPages có chia được dãy
// thành k tập sao cho tổng số trang của mỗi tập không vượt quá maxPages.
bool isFeasible(const vector<long long> &pages, int k, long long maxPages)
{
    int cnt = 1; // bắt đầu với 1 tập
    long long currentSum = 0;
    for (long long page : pages)
    {
        // Nếu cộng chương hiện tại vượt quá giới hạn, bắt đầu tập mới.
        if (currentSum + page > maxPages)
        {
            cnt++;
            currentSum = page;
        }
        else
        {
            currentSum += page;
        }
    }
    return (cnt <= k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> pages(n);
    long long sum = 0;
    long long maxPage = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
        sum += pages[i];
        maxPage = max(maxPage, pages[i]);
    }

    // Tìm kiếm nhị phân trong khoảng [maxPage, sum]
    long long low = maxPage, high = sum, ans = high;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (isFeasible(pages, k, mid))
        {
            ans = mid; // nếu khả thi, lưu lại kết quả và thử giảm giới hạn
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // nếu không khả thi, cần tăng giới hạn lên
        }
    }

    cout << ans << "\n";
    return 0;
}
