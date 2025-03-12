#include <iostream>
#include <vector>
#include <cassert>
#include <initializer_list>
#include "numpy.hpp"
int main()
{
    // Tạo một mảng 3 chiều kích thước 3 x 4 x 5
    numpy::ndarray<double> array({3, 4, 5});
    array({0, 0, 0}) = 10.0;
    std::cout << array;
    return 0;
}