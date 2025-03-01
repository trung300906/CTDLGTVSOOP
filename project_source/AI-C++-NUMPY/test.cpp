#include <bits/stdc++.h>
#include "algo/numpy.hpp"
// #include "linear_regression.hpp"
using namespace std;

int main()
{
    int rows, collom;
    cout << "hello and it run..." << endl;
    cin >> rows >> collom;
    numpy::ndarray a(rows, collom);
    numpy::ndarray b(rows, collom);
    cin >> a;
    cin >> b;
    cout << (a + b).transpose() << endl;
}