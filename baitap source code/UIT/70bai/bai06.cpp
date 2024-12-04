#include <iostream>
using namespace std;

void deleteSmallerThanX(int a[], int &n, int X)
{
    int newSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= X)
        {
            a[newSize++] = a[i];
        }
    }
    n = newSize;
}

int main()
{
    int a[] = {1, 4, 3, 6, 7, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int X = 4;
    deleteSmallerThanX(a, n, X);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
