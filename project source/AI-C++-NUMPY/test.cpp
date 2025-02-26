#include <bits/stdc++.h>
#include "numpy.hpp"
// #include "linear_regression.hpp"
using namespace std;

int main()
{
    int rows, collom;
    cin >> rows >> collom;
    numpy::ndarray a(rows, collom);
    numpy::ndarray b(rows, collom);
    cin >> a;
    cout << a[0][1] << endl;
}