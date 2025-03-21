#ifndef SIMD_INDEX_HPP
#define SIMD_INDEX_HPP
#include "based/header.hpp"

// matrix-matrix operations
template <typename data_type>
void simd_add(const data_type *A, const data_type *B, data_type *C, size_t shape); // add 2 matrix(+)

template <typename data_type>
void simd_sub(const data_type *A, const data_type *B, data_type *C, size_t shape); // sub 2 matrix (-)

// element-wise operations
template <typename data_type>
void simd_elem_mul(data_type *A, size_t shape, const data_type &scalor); // element-wise multiplication

template <typename data_type>
void simd_elem_div(data_type *A, size_t shape, const data_type &scalor); // element-wise division

template <typename data_type>
void simd_power(data_type *A, size_t shape, const data_type &scalor); // element-wise power

#endif