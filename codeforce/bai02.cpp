#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> key(n);
    for (auto &i : key)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        if (key[i].length() > 10)
        {
            cout << key[i][0] << key[i].length() - 2 << key[i][key[i].length() - 1] << endl;
        }
        else
        {
            cout << key[i] << endl;
        }
    }
}