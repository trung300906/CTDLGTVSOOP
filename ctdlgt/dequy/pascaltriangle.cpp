#include <bits/stdc++.h>
using namespace std;

int giaithua(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        return n * giaithua(n - 1);
    }
}
auto pascal(int n, int i, int dem)
{
    if (n == i)
    {
        cout << 1;
        return;
    }
    else
    {
        if (i == dem)
        {
            if (dem == 0)
                cout << setw((n - dem - 1) / 2 + 7) << ' ';
            cout << giaithua(dem) / (giaithua(i) * (giaithua(dem - i)));
            cout << endl;
            pascal(n, 0, ++dem);
        }
        else if (i != dem)
        {
            if (i == 0)
                cout << setw((n - dem - 1) / 2 + 7) << ' ';
            cout << giaithua(dem) / (giaithua(i) * (giaithua(dem - i)));
            cout << "\t";
            pascal(n, ++i, dem);
        }
    }
}
int main()
{
    int n, i = 0, dem = 0;
    cin >> n;
    pascal(n, i, dem);
}