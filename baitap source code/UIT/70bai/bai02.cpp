#include <iostream>
using namespace std;

bool isSymmetric(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
            return false;
    }
    return true;
}

int main()
{
    int a[] = {1, 2, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    if (isSymmetric(a, n))
    {
        cout << "Array is symmetric" << endl;
    }
    else
    {
        cout << "Array is not symmetric" << endl;
    }
    return 0;
}
