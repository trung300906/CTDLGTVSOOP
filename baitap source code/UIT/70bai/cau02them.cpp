#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int index;
    cin >> index;
    int indexl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == index)
        {
            indexl = i;
        }
    }
    cout << indexl << endl;
    return 0;
}