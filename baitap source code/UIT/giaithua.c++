#include <bits/stdc++.h>
using namespace std;

long long giaithua(int n)
{
    long long giaithua = 1;
    for (int i = 2; i <= n; i++)
    {
        giaithua *= i;
    }
    return giaithua;
}
int main()
{
    int n;
    cin >> n;
    cout << "giai thua cua " << n << " la: " << giaithua(n) << endl;
}