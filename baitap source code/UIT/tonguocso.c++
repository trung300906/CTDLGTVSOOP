#include <bits/stdc++.h>
using namespace std;

long long sumOfDivisors(long long n)
{
    long long total = 1;
    for (long long i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                total += i;
            }
            else
            {
                total += i + (n / i);
            }
        }
    }
    return total;
}

int main()
{
    long long n;
    cin >> n;
    cout << sumOfDivisors(n) << endl;
    return 0;
}
