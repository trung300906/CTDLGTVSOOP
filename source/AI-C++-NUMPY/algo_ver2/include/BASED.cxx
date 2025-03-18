#include "numpy.hpp"

namespace numpy
{
    template <typename data_type>
    std::vector<size_t> ndarraty<data_type>::shape()
    {
        return this->shape;
    }
}