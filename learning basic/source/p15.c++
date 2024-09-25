#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    int hieu = a - b;
    int tich = a * b;
    double thuong = double(a) / (b);
    cout << a << " + " << b << "  =  " << sum << endl;
    cout << a << " - " << b << "  =  " << hieu << endl;
    cout << a << " x " << b << "  =  " << tich << endl;
    cout << a << " : " << b << "  =  " << fixed << setprecision(2) << thuong << endl;
    return 0;
}