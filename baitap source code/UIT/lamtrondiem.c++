#include <bits/stdc++.h>
using namespace std;

int main()
{
    double diem;
    int n;
    cin >> diem >> n;
    double lam_tron = round(diem * n) / n;
    cout << setprecision(10) << lam_tron << endl;
    return 0;
}