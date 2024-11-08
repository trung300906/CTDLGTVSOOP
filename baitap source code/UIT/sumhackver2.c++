#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    long double total1 = 1;
    long double total2 = 1;
    long double total3 = 1;
    int tu = 1;
    int mau = 1;
    for (int i = 1; i <= n; i++)
    {
        total1 += pow(x, i);
        total2 += pow(x, 2 * i);
        tu *= x;
        mau *= i;
        total3 += double(tu) / mau;
    }
    cout << total1 << endl;
    cout << total2 << endl;
    cout << total3 << endl;
    return 0;
}