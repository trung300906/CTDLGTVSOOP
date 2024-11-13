#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double approximatePi(int n)
{
    long double total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += pow((-1), i) / (2 * i + 1);
    }
    return 4 * total;
}

int main()
{
    double n;
    cin >> n;
    cout << fixed << setprecision(5);
    cout << "" << approximatePi(n) << endl;

    return 0;
}