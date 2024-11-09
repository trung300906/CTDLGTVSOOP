#include <bits/stdc++.h>
using namespace std;

int ckn(int n, int k)
{
    if (k > n)
        return 0;
    if (n == 0 || k == n)
        return 1;
    return ckn(n - 1, k - 1) + ckn(n - 1, k);
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << ckn(n, k) << endl;
    return 0;
}