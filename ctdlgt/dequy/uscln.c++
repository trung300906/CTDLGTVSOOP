#include <bits/stdc++.h>
using namespace std;

int lcd(int a, int b)
{
    if (b == 0)
        return a;
    return lcd(b, a % b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << lcd(a, b) << endl;
}