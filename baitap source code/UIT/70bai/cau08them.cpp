#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &i : a)
        cin >> i;
    auto minindex = *min_element(a, a + n);
    cout << minindex << endl;
    return 0;
}