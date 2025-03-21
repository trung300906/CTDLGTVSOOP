#include <bits/stdc++.h>
using namespace std;

auto binary_search(vector<string> key, string m)
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
int main()
{
    int n;
    cin >> n;
    string m;
    vector<string> key(n);
    for (auto &i : key)
    {
        cin >> i;
    }
    sort(key.begin(), key.end());
    cin >> m;
    binary_search(key, m);
    // cout << binary_search_recursive(key, m, 0, key.size() - 1) << endl;
    return 0;
}