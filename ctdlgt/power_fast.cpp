#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

double power(double x, double y)
{
    if (y == 0)
        return 1;
    double res = power(x, y / 2);
    if (static_cast<int>(y) % 2)
        return res * res * x;
    else
        return res * res;
}
int main()
{
    double x = 2.0, y = 1000.0;
    cout << "pow: " << pow(x, y) << endl;
    cout << "powl: " << powl(x, y) << endl;
    cout << "__builtin_powl: " << __builtin_powl(x, y) << endl;
    // using recursive
    cout << power(x, y);
}
