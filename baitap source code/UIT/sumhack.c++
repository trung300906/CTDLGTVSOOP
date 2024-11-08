#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main()
{
    long double total1 = 1;
    long double total2 = 1;
    long double temp = 1;
    long double total3 = 1;
    int maud = 1;
    int n;
    cin >> n;
#if 0
        auto start = chrono::high_resolution_clock::now();
#endif
    for (int i = 2; i <= n; ++i)
    {
        {
            total1 += pow(i, i);
        }
        {
            temp *= i;
            total2 += temp;
        }
        {
            maud += i;
            total3 += 1.0 / maud;
        }
    }
#if 0
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
        cout << sizeof(total1) << endl;
        cout << sizeof(total2) << endl;
        cout << sizeof(total3) << endl;
#endif
    cout << total1 << endl;
    cout << total2 << endl;
    cout << total3 << endl;
    return 0;
}