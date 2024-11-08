#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
    cout << a << " " << b << " " << c;
}