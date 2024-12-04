#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
// 0 1 2 3 4 5 6 7 8 9 10 nan
int chenso(int &n, int a[], int needed, int index)
{
    if (index == n)
    {
        a[index] = needed;
        n++;
        return n;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        a[i + 1] = a[i];
        if (i == index)
        {
            a[i] = needed;
            n++;
            break;
        }
    }
    return needed;
}
int main()
{
    int n;
    cin >> n;
    int a[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int needed;
    cin >> needed;
    int index;
    cin >> index;
    chenso(n, a, needed, index);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}