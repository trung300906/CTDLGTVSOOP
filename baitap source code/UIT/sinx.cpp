#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float x;
    cin >> x;
    float tu = x;
    float mau = 1;
    float vcal = tu / mau;
    int temp = 1;
    for (int i = 1; i <= 15; i++)
    {
        tu *= -x * x;
        mau *= (2 * i) * (2 * i + 1);
        vcal += (tu / mau);
    }
    cout << fixed << setprecision(4) << vcal << endl;
}