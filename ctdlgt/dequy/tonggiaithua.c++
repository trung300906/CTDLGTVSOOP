#include <bits/stdc++.h>
using namespace std;
int giaithua(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        return n * giaithua(n - 1);
    }
}
int tongn(int n)
{
    if (n == 1)
        return 1;
    return giaithua(n) + tongn(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << tongn( n) << endl;
    return 0;
}