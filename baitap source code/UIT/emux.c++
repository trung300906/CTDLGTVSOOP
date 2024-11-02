#include <iostream>
using namespace std;

float process(int n, int x)
{
    float s = 1;
    int tu = x;
    int mau = 1;
    s += float(tu) / mau;
    for (int i = 2; i <= n; i++)
    {
        tu *= x;
        mau *= i;
        s += float(tu) / mau;
    }
    cout << s;
    return s;
}
int main()
{
    int n, x;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Sum = " << process(n, x) << endl;
    return 0;
}