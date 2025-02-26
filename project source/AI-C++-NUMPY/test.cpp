#include <bits/stdc++.h>
#include "numpy.hpp"
#include "function.hpp"
using namespace std;

int main()
{
    int rows, collom;
    cin >> rows >> collom;
    numpy::ndarray a(rows, collom);
    numpy::ndarray b(rows, collom);
    cin >> a;
    cin >> b;
    cout << a * 2;
}