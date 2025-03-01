#ifndef SPECS_ALGO_HPP
#define SPECS_ALGO_HPP
#include "numpy.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace numpy
{
    template <typename data_type>
    double ndarray<data_type>::mean();
    double ndarray<data_type>::variance();
    double ndarray<data_type>::standard_deviation();
    ndarray<data_type> ndarray<data_type>::normalize();
    ndarray<data_type> ndarray<data_type>::covariance_matrix();
    ndarray<data_type> ndarray<data_type>::correlation_matrix();
    ndarray<data_type> ndarray<data_type>::LU_composition();
    ndarray<data_type> ndarray<data_type>::cholesky_decomposition();
    ndarray<data_type> ndarray<data_type>::QR_decomposition();

    template <typename T>
    struct SVDResult
    {
        ndarray<T> U; // Ma trận trực giao (m x n)
        ndarray<T> S; // Ma trận đường chéo (n x n) chứa singular values
        ndarray<T> V; // Ma trận trực giao (n x n)
    };
    SVDResult<data_type> SVD_decomposition(const ndarray<data_type> &A);
    ndarray<data_type> ndarray<data_type>::eigen_value();
    ndarray<data_type> ndarray<data_type>::eigen_vector();
}
#endif