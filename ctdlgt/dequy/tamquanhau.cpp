#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
auto tamquanhau(int n, vector<int> &a, int count, int fill)
{
    if (count == n + 1)
        return a; // truong hop co so
    if (count <= n / 2)
    {
        a[count - 1] = fill;
        return tamquanhau(n, a, count + 1, fill + 2);
    }
    else if (count > n / 2)
    {
        if (count == n / 2 + 1)
        {
            fill -= a[count - 2] + 1;
            if (n % 12 == 3 || n % 12 == 9)
                swap(a[0], a[count - 2]);
        }
        a[count - 1] = fill;
        if (n % 2 == 0 && count != (n / 2 + 1) && n % 12 == 8)
        {
            if (count % 2 == 0)
                swap(a[count - 1], a[count - 2]);
        }
        if (n % 12 == 2)
        {
            if (a[count - 1] == 3 && a[count - 2] == 1)
                swap(a[count - 1], a[count - 2]);
            if (a[count - 1] == 5)
                swap(a[count - 1], a[n - 1]);
            if (count == n)
            {
                for (int i = 0; i < count; i++)
                {
                    if (a[i] == 0)
                    {
                        swap(a[i], a[count - 1]);
                        break;
                    }
                }
            }
        }
        if(n % 12 == 3 || n% 12 == 9){
            
        }
        return tamquanhau(n, a, count + 1, fill + 2);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    /*for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }*/
    tamquanhau(n, a, 1, 2);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}