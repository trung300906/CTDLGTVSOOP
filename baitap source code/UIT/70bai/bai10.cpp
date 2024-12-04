#include <iostream>
using namespace std;

bool isPrime(int n)
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
void separatePrimes(int a[], int n, int b[], int &m)
{
    m = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            b[m++] = a[i];
        }
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int b[100], m;

    separatePrimes(a, n, b, m);

    cout << "Prime numbers in array b: ";
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
