#include <bits/stdc++.h>
using namespace std;

// Hàm chuyển __int128 thành chuỗi
string toString(__int128 x)
{
    if (x == 0)
        return "0";
    bool neg = false;
    if (x < 0)
    {
        neg = true;
        x = -x;
    }
    string s;
    while (x > 0)
    {
        s.push_back('0' + (int)(x % 10));
        x /= 10;
    }
    if (neg)
        s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

__int128 cutting_tree(__int128 a, __int128 k, __int128 b, __int128 m, __int128 mid)
{
    return a * (mid - mid / k) + b * (mid - mid / m);
}

__int128 binary_search(__int128 a, __int128 k, __int128 b, __int128 m, __int128 n)
{
    __int128 left = 0, right = n;
    while (left < right)
    {
        __int128 mid = (left + right) / 2;
        if (cutting_tree(a, k, b, m, mid) >= n)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Dữ liệu đầu vào được đọc qua unsigned long long sau đó chuyển sang __int128
    unsigned long long temp_a, temp_k, temp_b, temp_m, temp_n;
    cin >> temp_a >> temp_k >> temp_b >> temp_m >> temp_n;

    __int128 a = temp_a, k = temp_k, b = temp_b, m = temp_m, n = temp_n;

    __int128 ans = binary_search(a, k, b, m, n);
    cout << toString(ans);
    return 0;
}
