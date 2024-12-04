#include <iostream>
#include <vector>
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
void printPrimes(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (primecheck(a[i]))
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int a[] = {10, 17, 23, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    printPrimes(a, n);
    return 0;
}
