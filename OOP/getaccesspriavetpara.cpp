#include <bits/stdc++.h>
using namespace std;

class Myclass
{
private:
    // cách tổ chwucs vùng nhớ
    // 1 class trong C++ được tổ chức để sắp cấc biến giống kiểu dữ liệu nhau sẽ ở gần chung các vùng nhớ của nhau
    // nếu có kiểu dữ liệu khác khác vùng nhớ, nhờ các kĩ thuật tối ưu trong kernel nên nó sẽ ở các vùng nhớ khác nhau(ở khác page trong memory)
    int value1 = 20;
    double value2 = 30;
    int value3 = 40;

public:
    // method 1 using function to return type
    auto getvalue1();
    auto getvalue2();
    auto getvalue3();
    // method 2 using friend function
    friend auto getvalue();
};
auto Myclass::getvalue1()
{
    return this->value1; // pointer this to define difference between value
}
auto getvalue()
{
    Myclass obj;
    return obj.value1;
}
int main()
{
    Myclass x;
    auto data = x.getvalue1(); // method 1
    auto dataset = getvalue(); // method 2
    int *ptr = (int *)&x;
    double *ptr_a = (double *)(ptr + 1);
    int *ptr_b = (int *)(ptr + 2);
    cout << data << endl;
    cout << dataset << endl;
    cout << *ptr; // just can access the first private parameters
    cout << "\n"
         << *ptr_a << endl;
    cout << "\n"
         << *ptr_b << endl;
    return 0;
}