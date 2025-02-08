#include <bits/stdc++.h>
using namespace std;

typedef class myclass
{
private:
    int a, b, c;

public:
    int d, e, f;
} mc;
int main()
{
    mc obj;
    // cout << obj.a; error due to private method
    obj.d = 10;
    cout << obj.d;
}