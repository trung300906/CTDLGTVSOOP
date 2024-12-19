#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<tuple<int, int, bool>> test(n);
    for (auto &i : test)
    {
        tuple<int, int, bool> temp;
        temp = make_tuple(1, 2, true);
        i = temp;
    }
}