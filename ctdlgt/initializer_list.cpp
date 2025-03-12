#include <initializer_list>
#include <iostream>
#include <vector>
class MyClass
{
public:
    MyClass(std::initializer_list<int> list)
    {
        std::cout << "MyClass khởi tạo với các giá trị: ";
        for (int elem : list)
        {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
};

class Myclass_child
{
public:
    Myclass_child(std::vector<int> list)
    {
        std::cout << "Myclass_child khoi tao voi cac gia tri: ";
        for (auto &elem : list)
        {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
};
int main()
{
    MyClass obj = {10, 20, 30}; // Gọi constructor nhận std::initializer_list<int>
    Myclass_child construc({1, 2, 5});
    Myclass_child objobj = {1, 2, 1};
    std::vector<int> A = {1, 2, 3};
    Myclass_child elemememe = A;
    return 0;
}
