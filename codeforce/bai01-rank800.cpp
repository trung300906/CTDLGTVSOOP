#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w;
    cin >> w;
    if (w <= 3)
        cout << "NO";
    if (w > 3)
    {
        if (w % 2 == 0)
            cout << "YES";
        else
        {
            for (int i = 2; i < w; i += 2)
            {
                if (i > w)
                    continue;
                if ((w - i) % 2 == 0)
                {
                    cout << "YES";
                    return 0;
                }
                else
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
}