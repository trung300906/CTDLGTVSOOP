#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(10, 5);
    auto p = v.begin(), q = v.end() - 1;
    cout << *p << " " << *q << endl;
    //cointainer must be used with containers iterator to interact or sign an element with iterator of cointainer
    vector<int>::iterator it_begin = v.begin(), it_end = v.end();
    cout << *it_begin << " " << *it_end << endl
    // we using dot '.' for access through memory to access some elements of pair or tuple or struct or an OOP and something else
}