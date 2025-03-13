#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>
#include "numpy.h"
#include "linear_regression.hpp"
#include "specs_algo.hpp"

namespace numpy
{
    template <typename data_type>
    ndarray<data_type> linear_regression<data_type>::predict(const ndarray<data_type> &X, const ndarray<data_type> &theta)
    {
        if (X.size_matrix(1) != theta.size_matrix(0))
        {
            throw std::runtime_error("dimension error");
        }
        else
        {
            return X * theta;
        }
    }
}