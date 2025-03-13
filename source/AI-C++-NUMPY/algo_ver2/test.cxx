#include "include/numpy.hpp"
int main()
{
    numpy::ndarray<double> A({3, 3});
    std::cin >> A;
    numpy::ndarray<double> B({3, 3});
    std::cin >> B;
    numpy::ndarray<double> C = A;
    std::cout << C;
}