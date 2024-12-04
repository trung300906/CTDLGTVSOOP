#include <iostream>
using namespace std;

int deleteAtIndex(int a[], int &n, int k)
{
    if (k < 0 || k >= n)
        return 0;
    for (int i = k; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    return 1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2; // delete 3
    if (deleteAtIndex(a, n, k))
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Invalid index" << endl;
    }
    return 0;
}
