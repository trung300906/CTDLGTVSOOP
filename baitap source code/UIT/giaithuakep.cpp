#include <bits/stdc++.h>
using namespace std;

unsigned long long giaithuakep(int n)
{
    if (n == 2 || n == 1)
        return n;
    return n * giaithuakep(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << giaithuakep(n) << endl;
    return 0;
}