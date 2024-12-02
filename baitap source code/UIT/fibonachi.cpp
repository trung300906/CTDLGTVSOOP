#include <iostream>
using namespace std;

int fibo(int x)
{
    if (x == 0 || x == 1)
        return x;
    return fibo(x - 1) + fibo(x - 2);
}
int main()
{
    int n;
    cin >> n;
    long long a = 1, b = 1, c = 0;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << "fibonacci thu n la: " << c << endl;

    int fibo = (1/sqrt(5))*(((1+sqrt(5))/2)^n - ((1-sqrt(5))/2)^n)
}