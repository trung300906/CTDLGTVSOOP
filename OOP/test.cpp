#if 0
#include <iostream>

    class MyClass
    {
    private:
        int a = 10;
        double b = 20.5;
        char c = 'X';
    };

    int main()
    {
        MyClass obj;

        // Lấy địa chỉ của obj
        int *ptr_a = (int *)&obj;
        double *ptr_b = (double *)(ptr_a + 1); // Giả định int có kích thước 4 bytes
        char *ptr_c = (char *)(ptr_b + 1);     // Giả định double có kích thước 8 bytes

        std::cout << "a = " << *ptr_a << std::endl;
        std::cout << "b = " << *ptr_b << std::endl; // sai do padding
        std::cout << "c = " << *ptr_c << std::endl; // Có thể sai do padding!

        return 0;
    }
#endif
#if 0
#include <iostream>
#include <cstdint>

class MyClass
{
private:
    int a = 10;
    double b = 20.5;
    char c = 'X';
};

int main()
{
    MyClass obj;
    std::byte *raw = reinterpret_cast<std::byte *>(&obj);

    // Duyệt qua bộ nhớ của obj
    for (size_t i = 0; i < sizeof(MyClass); ++i)
    {
        std::cout << std::to_integer<int>(raw[i]) << " ";
    }
    std::cout << std::endl;
}
#endif
#if 0
#include <iostream>
#include <cstddef>

class MyClass
{
private:
    int a = 10;
    double b = 20.5;
    char c = 'X';

public:
    void printOffsets()
    {
        std::cout << "Offset of a: " << offsetof(MyClass, a) << std::endl;
        std::cout << "Offset of b: " << offsetof(MyClass, b) << std::endl;
        std::cout << "Offset of c: " << offsetof(MyClass, c) << std::endl;
    }
};

int main()
{
    MyClass obj;
    obj.printOffsets();
}
#endif