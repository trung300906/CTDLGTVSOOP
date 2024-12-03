#include <iostream>
using namespace std;

int modulo(int a, int b)
{
    if (b == 0)
        return -1;
    if (a < b)
        return a;
    return modulo(a - b, b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << modulo(a, b) << endl;
}