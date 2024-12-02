#include <bits/stdc++.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
bool prime(int n)
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
int TongUocSoNguyenTo(int a, int b)
{
    int sum = 0;
    for (int i = 2; i <= gcd(a, b); i++)
    {
        if (a % i == 0 && b % i == 0 && prime(i))
            sum += i;
    }
    if (sum == 0)
        sum = -1;
    return sum;
}
int main()
{
    int a;
    int b;
    std::cin >> a >> b;
    std::cout << TongUocSoNguyenTo(a, b) << std::endl;
}