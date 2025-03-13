#ifndef SIMD_HPP
#define SIMD_HPP
#include "header.hpp"

template <typename data_type>
void simd_add(const data_type *A, const data_type *B, const data_type *C, size_t n)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        for (; i + 16 <= n; i += 16)
        {
            __m512 a = _mm512_loadu_ps(&A[i]);
            __m512 b = _mm512_loadu_ps(&B[i]);
            __m512 c = _mm512_add_ps(a, b);
            _mm512_storeu_ps(&C[i], c);
        }
    }
    else if constexpt (std::is_same_v<data_type, double>)
    {
        for (; i + 8 <= n; i += 8)
        {
            __m512d a = _mm512_loadu_pd(&A[i]);
            __m512d b = _mm512_loadu_pd(&B[i]);
            __m512d c = _mm512_add_pd(a, b);
            _mm512_storeu_pd(&C[i], c);
        }
    }
    else if constexpr (std::is_integral_v<data_type>)
    {
        for (; i + 16 <= n; i += 16)
        {
            __m512 a = _mm512_loadu_si512(&A[i]);
            __m512 b = _mm512_loadu_si512(&B[i]);
            __m512 c = _mm512_add_si512(a, b);
            _mm512_storeu_si512(&C[i], c);
        }
    }
    for (; i < n; i++)
    {
        C[i] = A[i] + B[i];
    }
}
template <typename data_type>
void simd_sub(const data_type *A, const data_type *B, const data_type *C, size_t n)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        for (; i + 16 <= n; i += 16)
        {
            __m512 a = _mm512_loadu_ps(&A[i]);
            __m512 b = _mm512_loadu_ps(&B[i]);
            __m512 c = _mm512_sub_ps(a, b);
            _mm512_storeu_ps(&C[i], c);
        }
    }
    else if constexpt (std::is_same_v<data_type, double>)
    {
        for (; i + 8 <= n; i += 8)
        {
            __m512d a = _mm512_loadu_pd(&A[i]);
            __m512d b = _mm512_loadu_pd(&B[i]);
            __m512d c = _mm512_sub_pd(a, b);
            _mm512_storeu_pd(&C[i], c);
        }
    }
    else if constexpr (std::is_integral_v<data_type>)
    {
        for (; i + 16 <= n; i += 16)
        {
            __m512 a = _mm512_loadu_si512(&A[i]);
            __m512 b = _mm512_loadu_si512(&B[i]);
            __m512 c = _mm512_sub_si512(a, b);
            _mm512_storeu_si512(&C[i], c);
        }
    }
    for (; i < n; i++)
    {
        C[i] = A[i] - B[i];
    }
}

#endif