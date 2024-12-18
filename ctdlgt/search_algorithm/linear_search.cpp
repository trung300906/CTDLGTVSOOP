#include <bits/stdC++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (auto &i : a)
    {
        if (i == n)
        {
            return true;
        }
    }
}