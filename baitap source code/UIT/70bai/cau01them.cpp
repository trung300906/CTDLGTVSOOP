#include <bits/stdc++.h>
using namespace std;
;

int main()
{

    int n, count = 0;
    do
    {
        if (count > 0)
            cout << "wrong intput type agian..." << endl;
        cin >> n;
        count++;
    } while (n < 0 || n > 150);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}