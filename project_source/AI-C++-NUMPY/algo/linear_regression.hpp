#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>
#include "numpy.h"

namespace numpy
{
    template <typename data_type>
    class linear_regression : public ndarray<data_type>
    {
    public:
        // linear_regression.hpp
        ndarray<data_type> predict(const ndarray<data_type> &X, const ndarray<data_type> &theta);
        ndarray<data_type> cost_function(const ndarray<data_type> &X, const ndarray<data_type> &y, const ndarray<data_type> &theta);
        struct gradient_return
        {
            ndarray<data_type> cost_history;
            ndarray<data_type> theta_history;
            ndarray<data_type> theta;
        };
        gradient_return gradient_descent(ndarray<data_type> &X, ndarray<data_type> &y, ndarray<data_type> &theta, const data_type &learning_rate, const size_t &iteration);
        double accuracy(ndarray<data_type> &y_true, ndarray<data_type> &y_pred);
    };
}
#endif