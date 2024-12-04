
#include <iostream>
using namespace std;
#define MAX 100

int Nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    return a[0];
}
int firstnum(int n)
{
    while (n >= 10)
    {
        n /= 10;
    }
    if (n == 1)
        return 1;
    if (n == 4)
        return 4;
    return -1;
}
int isBenford(int a[], int n)
{
    int count_1 = 0;
    int count_4 = 0;
    for (int i = 0; i < n; i++)
    {
        if (firstnum(a[i]) == 1)
        {
            count_1++;
            // cout << firstnum(a[i]) << endl;
        }

        if (firstnum(a[i]) == 4)
        {
            count_4++;
            // cout << firstnum(a[i]) << endl;
        }
    }
    if (count_1 == 3 && count_4 == 1)
        return true;
    return false;
}
int main()
{
    int a[MAX], n = 10;
    Nhapmang(a, n);
    if (isBenford(a, n) == true)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    return 0;
}