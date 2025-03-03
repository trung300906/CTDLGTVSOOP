```cpp
#ifndef SPECS_ALGO_HPP
#define SPECS_ALGO_HPP
#include "numpy.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace numpy
{
    double ndarray::mean();
    double ndarray::variance();
    double ndarray::standard_deviation();
    ndarray ndarray::normalize();
    ndarray ndarray::covariance_matrix();
    ndarray ndarray::correlation_matrix();
    ndarray ndarray::LU_composition();
    ndarray ndarray::cholesky_decomposition();
    ndarray ndarray::QR_decomposition();
    ndarray ndarray::SVD_decomposition();
    ndarray ndarray::eigen_value();
    ndarray ndarray::eigen_vector();
    ndarray ndarray::solve_linear_equation(const ndarray &nd);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2, const ndarray &nd3);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2, const ndarray &nd3, const ndarray &nd4);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2, const ndarray &nd3, const ndarray &nd4, const ndarray &nd5);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2, const ndarray &nd3, const ndarray &nd4, const ndarray &nd5, const ndarray &nd6);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2, const ndarray &nd3, const ndarray &nd4, const ndarray &nd5, const ndarray &nd6, const ndarray &nd7);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2, const ndarray &nd3, const ndarray &nd4, const ndarray &nd5, const ndarray &nd6, const ndarray &nd7, const ndarray &nd8);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2, const ndarray &nd3, const ndarray &nd4, const ndarray &nd5, const ndarray &nd6, const ndarray &nd7, const ndarray &nd8, const ndarray &nd9);
    ndarray ndarray::solve_linear_equation(const ndarray &nd, const ndarray &nd2, const ndarray &nd3, const ndarray &nd4, const ndarray &nd5, const ndarray &nd6, const ndarray &nd7, const ndarray &nd8, const ndarray &nd9, const ndarray &nd10);
}
#endif
````

include into [[specs_algo.cpp]], [[linear_regression.hpp]], [[test.cpp]]