#include <bits/stdc++.h>
using namespace std;
#if 1
// in class
class myclass
{
public:
    void method_funct()
    {
        cout << "this is from method_fubc_myclass" << endl;
    }
};
class myclass_child : public myclass
{
public:
    void method_func_child()
    {
        cout << "=============================" << endl;
    }
};
int main()
{
    myclass_child obj;
    obj.method_func_child();
    myclass obj2;
    obj2 = static_cast<
}
#endif