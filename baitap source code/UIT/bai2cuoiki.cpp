#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll int_sqrt(ll n) {
    ll left = 0, right = n;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (mid * mid <= n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - 1;
}

ll div(ll n)
{
    ll count = 0;
    ll sqrtN = int_sqrt(n);
    for (ll i = 1; i <= sqrtN; i++)
    {
        if (n % i == 0)
            count += 2;
    }
    if (sqrtN * sqrtN == n)
    {
        count--;
    }
    return count;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> divisor(n);
    for (ll i = 1; i < n; i++)
    {
        divisor[i] = div(i);
    }
    ll count = 0;
    for (ll i = 1; i < n; i++)
    {
        count += divisor[i] * divisor[n - i];
    }
    cout << count << endl;
    return 0;
}