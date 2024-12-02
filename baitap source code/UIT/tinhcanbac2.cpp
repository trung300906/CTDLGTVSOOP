#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n = 10;
    double tinh = 1;
    for (int i = 2; i <= n; i++)
    {
        tinh = sqrt((double)tinh + i);
    }
    cout << "Ket qua: " << setprecision(5) << tinh << endl;
    return 0;
}