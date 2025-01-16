#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1 + 1e6;

int n;
bool mark[MaxN];

int main()
{
    freopen("CTDL.inp", "r", stdin);
    freopen("CTDL.out", "w", stdout);
    cin >> n;
    for (int i = 2; i * i <= n; ++i)
        if (!mark[i])
            for (int j = 2; i * j <= n; ++j)
                mark[i * j] = 1;
    // Kết thúc vòng lặp, nếu mark[x] == 0 thì x là số nguyên tố và ngược lại

    return 0;
}
