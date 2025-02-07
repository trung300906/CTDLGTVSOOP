#include <bits/stdc++.h>
using namespace std;

class myclass
{
private:
    int value1;
    int value2;
    int value3;

public:
    auto getaccess();
    auto changevalue();
    auto getaccess_changevalue();
    // method 2 using friend function
    friend int main(); // not recommend
    friend auto getvalue(myclass &);
};

auto myclass::changevalue()
{
    this->value1 = 10;
    this->value2 = 20;
    this->value3 = 40;
}
auto myclass::getaccess()
{
    cout << this->value1 << " " << this->value2 << " " << this->value3;
}

auto getvalue(myclass &test)
{
    return test.value1;
}
int main()
{
    myclass test;
    test.changevalue();
    test.getaccess();
    cout << "\n" << test.value1;
    cout << "\n " << getvalue(test) << endl;
}