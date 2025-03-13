#include "numpy.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>

namespace numpy
{
    template <typename data_type>
    void ndarray<data_type>::setter(const ndarray<data_type> &nd)
    {
        data = nd.data;
        rows = nd.rows;
        collom = nd.collom;
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::getter() const
    {
        return *this;
    }
}