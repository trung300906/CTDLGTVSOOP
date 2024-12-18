#include <bits/stdc++.h>
using namespace std;

vector<int> binary_find_first(vector<int> vec, int m, vector<int> &res)
{
    int left = 0, right = vec.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] == m)
        {
            res.push_back(mid);
            right = mid - 1;
        }
        if (vec[mid] < m)
        {
            left = mid + 1;
        }
        if (vec[mid] > m)
        {
            right = mid - 1;
        }
    }
    return res; // Element not found in vector.
}
vector<int> binary_find_last(vector<int> vec, int m, vector<int> &res)
{
    int left = 0, right = vec.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] == m)
        {
            res.push_back(mid);
            left = mid + 1;
        }
        if (vec[mid] < m)
        {
            left = mid + 1;
        }
        if (vec[mid] > m)
        {
            right = mid - 1;
        }
    }
    return res; // Element not found in vector.
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (auto &i : vec)
    {
        cin >> i;
    }
    sort(vec.begin(), vec.end());
    vector<int> res;
    binary_find_first(vec, m, res);
    cout << *res.begin() << endl;
    cout << "\n ====================" << endl;
    res.clear();
    res.shrink_to_fit();
    binary_find_last(vec, m, res);
    cout << *(res.end() - 1) << endl;
    cout << "\n =======================" << endl;
    return 0;
}