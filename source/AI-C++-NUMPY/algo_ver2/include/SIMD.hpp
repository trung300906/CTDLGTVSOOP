#ifndef SIMD_HPP
#define SIMD_HPP
#include "header.hpp"

template <typename data_type>
void simd_add(const data_type *A, const data_type *B, const data_type *C, size_t n)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
    }
    else if constexpt (std::is_same_v<data_type, double>)
    {
    }
    else if constexpr (std::is_same_v<data_type, int>)
    {
    }
}
void simd_sub(const data_type *A, const data_type *B, const data_type *C, size_t n)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
    }
    else if constexpt (std::is_same_v<data_type, double>)
    {
    }
    else if constexpr (std::is_same_v<data_type, int>)
    {
    }
}

#endif