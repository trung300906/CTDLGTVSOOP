#include <bits/stdc++.h>
using namespace std;

bool primecheck(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n < 3 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &i : a)
    {
        cin >> i;
    }
    int count = 0;
    for (auto &i : a)
    {
        if (primecheck(i))
        {
            cout << i << " ";
            count++;
        }
    }
    if (count > 0)
        return 0;
    if (count == 0)
        cout << 0;
}