#include <bits/stdc++.h>
using namespace std;

int padovan(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return 1;
    return padovan(n - 2) + padovan(n - 3);
}
int main()
{
    int n;
    cin >> n;
    cout << padovan(n) << endl;
}