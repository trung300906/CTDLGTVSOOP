#include <iostream>
#include <iomanip>
using namespace std;
#include <math.h>

float calculate(int n)
{
    if (n == 1)
        return n;
    return sqrt(n + calculate(n - 1));
}
int main()
{
    int n;
    cin >> n;
    cout << fixed << setprecision(2) << calculate(n);
    return 0;
}