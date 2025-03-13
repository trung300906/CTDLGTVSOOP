#ifndef SIMD_HPP
#define SIMD_HPP
#include <iostream>
#include <vector>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <string>
#include <immintrin.h> // AVX2
#include <algorithm>
#include <execution>

/*
this is module for using SIMD for parallelism multiple data(used AVX)
for more please follow:
https://en.wikipedia.org/wiki/Single_instruction,_multiple_data

check compatible using avx:
linux platform:
grep -m1 'flags' /proc/cpuinfo | grep -o 'avx[^ ]*'
or:
lscpu | grep -i avx
windows platform:

*/
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