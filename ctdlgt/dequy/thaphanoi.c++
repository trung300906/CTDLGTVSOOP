#include <bits/stdc++.h>
using namespace std;

void tower(int n, char x, char y, char z)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << x << " to " << z << endl;
        return;
    }
    tower(n - 1, x, z, y);
    cout << "Move disk " << n << " from " << x << " to " << z << endl;
    tower(n - 1, y, x, z); // Move the remaining disks to the auxiliary peg.
}
int main()
{
    int n;
    cin >> n;
    tower(n, 'A', 'B', 'C');
}