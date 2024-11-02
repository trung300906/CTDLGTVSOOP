#include <iostream>
using namespace std;

long long power(int x, int n)
{
    long long s = 1;
    for (int i = 1; i <= n; i++)
    {
        s *= x;
    }
    return s;
}
int main()
{
    int x, n;
    cout << "nhap so can tinh: ";
    cin >> x;
    cout << "nhap so mu: ";
    cin >> n;
    cout << "gia tri cua " << x << "^" << n << " la: " << power(x, n) << endl;
}