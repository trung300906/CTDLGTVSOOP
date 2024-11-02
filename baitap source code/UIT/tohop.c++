#include <iostream>
using namespace std;

long double tohop(int n, int k)
{
    long double result = 1;
    for (int i = 1; i <= (n - k); ++i)
    {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}

int main()
{
    int n, k;
    int count = 0;
    do
    {
        if (count > 0)
            cout << "nhap lai...:";
        else
            cout << "nhap n va k: ";
        cin >> n >> k;
        count++;
    } while ((n < k) || ((n < 50) && (k < 50)));
    cout << tohop(n, k) << endl;
}