#include <bits/stdc++.h>
#include "algo/numpy.hpp"

int main()
{
    std::cout << "hello and it runiing,,, " << std::endl;
    numpy::ndarray A(3, 3);
    numpy::ndarray B(3, 3);
    std::cin >> A;
    B = A;
    std::cout << "debug: \n"
              << A.adj() << std::endl;
}