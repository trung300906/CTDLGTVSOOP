#include <bits/stdc++.h>
using namespace std;

/*
✅ private methods chỉ có thể truy cập thông qua phương thức public hoặc protected của chính class đó.
✅ protected methods có thể được truy cập từ class con, nhưng không thể truy cập trực tiếp từ bên ngoài class.
*/
class myclass
{
protected:
    int value1;
    void print_protected()
    {
        cout << "from protected of myclass: " << value1 << endl;
    }

private:
    int value2;
    void print_private()
    {
        cout << "from private of myclass: " << value2 << endl;
    }

public:
    int value3;
    void print_public_1()
    {
        cout << "from public of myclass: " << value3 << endl;
    }
    // using getter setter
    void print_public_2()
    {
        cout << "value from private of myclass: " << value2 << endl;
    }
    void using_private_method()
    {
        print_private();
    }
    void using_protected_method()
    {
        print_protected();
    }
};

class myclass_child : public myclass
{
public:
    void using_protected_method_myclass()
    {
        print_protected();
    }
};
int main()
{
    myclass obj;
    obj.print_public_1();
    obj.print_public_2();
    // obj.print_protected(); => error, cannot access out of class with private
    // obj.print_private(); => err, cannot access out of class of private
    obj.using_private_method();
    obj.using_protected_method();
    myclass_child obj2;
    obj2.using_protected_method_myclass();
}