#include <bits/stdc++.h>
using namespace std;

int binary(int n)
{
    if (n == 0)
        return 0;
    return (n % 2) + 10 * binary(n / 2);
}
int octal(int n)
{
    if (n == 0)
        return 0;
    return (n % 8) + 8 * octal(n / 8);
}

int hex(int n)
{
    char hex_digits[] = "0123456789ABCDEF";
    if (n == 0)
        return 0;
    return hex_digits[n % 16] + hex(n / 16);
}
int main()
{
    int n;
    cin >> n;
    cout << binary(n) << endl;
    cout << octal(n) << endl;
    cout << hex(n) << endl;
    return 0;
}