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
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        if (primecheck(a[i]))
        {
            cout << a[i] << " ";
            break;
        }
    }
}