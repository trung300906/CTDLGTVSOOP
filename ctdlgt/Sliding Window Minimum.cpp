#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1 + 1e5;

int n, k, a[MaxN];
deque<int> dq;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        if (!dq.empty() && i - dq.front() + 1 > k)
            dq.pop_front();
        while (!dq.empty() && a[i] < a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            cout << a[dq.front()] << " ";
    }

    return 0;
}
