#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<int> a(n);
    generate(a.begin(), a.end(), rand);
    sort(a.begin(), a.end());
    vector<int>::iterator upper = upper_bound(a.begin(), a.end(), 8);
    cout << *upper << endl;
}