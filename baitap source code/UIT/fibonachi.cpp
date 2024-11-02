#include <iostream>
using namespace std;

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
}