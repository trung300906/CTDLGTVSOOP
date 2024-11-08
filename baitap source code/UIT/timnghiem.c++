#include <bits/stdc++.h>
using namespace std;

double timnghiem(double a, double b)
{
    if (a == 0 && b == 0)
    {
        cout << "ℝ";
        return 0;
    }
    if (a == 0 && b != 0)
    {
        cout << "Ø";
        return 0;
    }
    if (a != 0)
    {
        cout << "{" << -b / a << "}";
        return 0;
    }
    return -b / a;
}
int main()
{
    double a, b;
    cin >> a >> b;
    timnghiem(a, b);
}