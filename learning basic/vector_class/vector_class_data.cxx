#include <bits/stdc++.h>
using namespace std;

void foo(const int *A)
{
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo(a.data());
}