#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<type/class/struct/alias_defined/pair/tuple> alias(size, value first);
    vector<int> an = {1, 2, 3, 4, 5, 6};
    vector<int>::iterator itr = an.begin();
    itr++;
    cout << *itr << " "; // 2
}