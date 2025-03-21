#include <bits/stdc++.h>
using namespace std;

auto binary_search(vector<int> key, int m)
{
    int left = 0, right = key.size() - 1;
    int count = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (m == key[mid])
        {
            count++;
            cout << mid << "\n"
                 << count << "\n"; // Xuất vị trí và số lần duyệt
            return;
        }

        if (m > key[mid])
        {
            left = mid + 1;
            count++;
        }
        if (m < key[mid])
        {
            right = mid - 1;
            count++;
        }
    }
    cout << -1;
}
#if 0
bool binary_search_recursive(vector<int> key, int m, int left, int right, int mid = 0)
{
    mid = (left + right) / 2;
    if (m < key[mid])
    {
        return binary_search_recursive(key, m, mid + 1, right, mid);
    }
    if (m > key[mid])
    {
        return binary_search_recursive(key, m, left, mid - 1, mid);
    }
    if (key[mid] == m)
    {
        return true;
    }
    return false;
}
#endif
int main()
{
    int n, m;
    cin >> n;
    vector<int> key(n);
    for (auto &i : key)
        cin >> i;
    sort(key.begin(), key.end());
    cin >> m;
    binary_search(key, m);
    // cout << binary_search_recursive(key, m, 0, key.size() - 1) << endl;
    return 0;
}