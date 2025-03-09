#ifndef SPECS_ALGO_HPP
#define SPECS_ALGO_HPP
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>
#include "numpy.hpp"

namespace numpy
{
    template <typename data_type>
    class specs_algo : public ndarray<data_type>
    {
    public:
        // specs_algo in file specs_algo.hpp
        double mean();
        double variance();
        double standard_deviation();
        ndarray<data_type> normalize();
        ndarray<data_type> covariance_matrix();
        ndarray<data_type> correlation_matrix();
        ndarray<data_type> LU_composition();
        ndarray<data_type> cholesky_decomposition();
        ndarray<data_type> QR_decomposition();
        struct SVDResult
        {
            ndarray<data_type> U; // Ma trận trực giao (m x n)
            ndarray<data_type> S; // Ma trận đường chéo (n x n) chứa singular values
            ndarray<data_type> V; // Ma trận trực giao (n x n)
        };
        SVDResult SVD_decomposition(const ndarray<data_type> &A);
        ndarray<data_type> eigen_value();
        ndarray<data_type> eigen_vector();
    };
}
#endif