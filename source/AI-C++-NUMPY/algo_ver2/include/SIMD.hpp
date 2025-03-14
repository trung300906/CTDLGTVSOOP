#ifndef SIMD_HPP
#define SIMD_HPP
#include "header.hpp"

template <typename data_type>
void simd_add(const data_type *A, const data_type *B, data_type *C, size_t n)
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
    else if constexpr (std::is_same_v<data_type, double>)
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
        using int_type = std::conditional_t<(sizeof(data_type) == 8), __m512i, __m512i>;
        for (; i + 16 <= n; i += 16)
        {
            int_type a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
            int_type b = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&B[i]));
            int_type c = _mm512_add_epi32(a, b);
            _mm512_storeu_si512(reinterpret_cast<__m512i *>(&C[i]), c);
        }
    }
    for (; i < n; i++)
    {
        C[i] = A[i] + B[i];
    }
}

template <typename data_type>
void simd_sub(const data_type *A, const data_type *B, data_type *C, size_t n)
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
    else if constexpr (std::is_same_v<data_type, double>)
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
        using int_type = std::conditional_t<(sizeof(data_type) == 8), __m512i, __m512i>;
        for (; i + 16 <= n; i += 16)
        {
            int_type a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
            int_type b = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&B[i]));
            int_type c = _mm512_sub_epi32(a, b);
            _mm512_storeu_si512(reinterpret_cast<__m512i *>(&C[i]), c);
        }
    }
    for (; i < n; i++)
    {
        C[i] = A[i] - B[i];
    }
}

#endif