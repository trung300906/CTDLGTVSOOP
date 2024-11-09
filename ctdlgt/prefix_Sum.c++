#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
#if 0
        vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(rand() % 1000 + 1);
        }
        vector<int> prefix_Sum(a.size(), 0);
        for (int i = 0; i <= prefix_Sum.size(); i++)
        {
            prefix_Sum[i] = prefix_Sum[i - 1] + a[i];
        }
        int x, y;
        cin >> x >> y;
        cout << "sum from " << x << " to " << y << " of a array is: " << abs(prefix_Sum[y] - prefix_Sum[x]);
#endif
#if 1
    vector<vector<int>> a;
    
#endif
    return 0;
}