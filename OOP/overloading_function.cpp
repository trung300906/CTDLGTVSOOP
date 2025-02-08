#include <bits/stdc++.h>
using namespace std;

ios_base::sync_with_stdio(TRUE);
cin.tie(NULL);
class myclass
{
private:
    int value1;
    int value2;
    int value3;

public:
    myclass(int a = 0, int b = 0, int c = 0) : value1(a), value2(b), value3(c) {};
    decltype(auto) operator+(myclass const &b)
    {
        myclass temp;
        temp.value1 = value1 + b.value1;
        temp.value2 = value2 + b.value2;
        temp.value3 = value3 + b.value3;
        return temp;
    }
    friend ostream &operator<<(ostream &out, myclass a)
    {
        out << a.value1 << " " << a.value2 << " " << a.value3;
        return out;
    }
    friend istream &operator>>(istream &in, myclass &a)
    {
        in >> a.value1 >> a.value2 >> a.value3;
        return in;
    }
};
int main()
{
    myclass x;
    myclass y;
    cin >> x;
    cin >> y;
    myclass c = x + y;
    cout << c;
}