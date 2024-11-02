#include <iostream>
#include <math.h>
using namespace std;
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

int main()
{
    int s = 2;
    int n;
    cin >> n;
    for (int i = 3; i < n; i++)
    {
        if (prime(i))
        {
            s += i;
        }
    }
    cout << "tong la: " << s << endl;
    return 0;
}