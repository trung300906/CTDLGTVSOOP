```cpp
#ifndef SIMD_HPP // protection header block
#define SIMD_HPP
#include "header.hpp"

template <typename data_type>
void simd_add(const data_type *A, const data_type *B, data_type *C, size_t shape)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        for (; i + 16 <= shape; i += 16)
        {
            __m512 a = _mm512_loadu_ps(&A[i]);
            __m512 b = _mm512_loadu_ps(&B[i]);
            __m512 c = _mm512_add_ps(a, b);
            _mm512_storeu_ps(&C[i], c);
        }
    }
    else if constexpr (std::is_same_v<data_type, double>)
    {
        for (; i + 8 <= shape; i += 8)
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
        for (; i + 16 <= shape; i += 16)
        {
            int_type a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
            int_type b = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&B[i]));
            int_type c = _mm512_add_epi32(a, b);
            _mm512_storeu_si512(reinterpret_cast<__m512i *>(&C[i]), c);
        }
    }
    // process data haven't finished yet
    for (; i < shape; i++)
    {
        C[i] = A[i] + B[i];
    }
}

template <typename data_type>
void simd_sub(const data_type *A, const data_type *B, data_type *C, size_t shape)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        for (; i + 16 <= shape; i += 16)
        {
            __m512 a = _mm512_loadu_ps(&A[i]);
            __m512 b = _mm512_loadu_ps(&B[i]);
            __m512 c = _mm512_sub_ps(a, b);
            _mm512_storeu_ps(&C[i], c);
        }
    }
    else if constexpr (std::is_same_v<data_type, double>)
    {
        for (; i + 8 <= shape; i += 8)
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
        for (; i + 16 <= shape; i += 16)
        {
            int_type a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
            int_type b = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&B[i]));
            int_type c = _mm512_sub_epi32(a, b);
            _mm512_storeu_si512(reinterpret_cast<__m512i *>(&C[i]), c);
        }
    }
    // process data haven't finished yet
    for (; i < shape; i++)
    {
        C[i] = A[i] - B[i];
    }
}

template <typename data_type>
void simd_elem_mul(data_type *A, size_t shape, const data_type &scalor)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        __m512 scalar_vec = _mm512_set1_ps(scalor);
        for (; i + 16 <= shape; i += 16)
        {
            __m512 a = _mm512_loadu_ps(&A[i]);
            a = _mm512_mul_ps(a, scalar_vec);
            _mm512_storeu_ps(&A[i], a);
        }
    }
    else if constexpr (std::is_same_v<data_type, double>)
    {
        __m512d scalar_vec = _mm512_set1_pd(scalor);
        for (; i + 8 <= shape; i += 8)
        {
            __m512d a = _mm512_loadu_pd(&A[i]);
            a = _mm512_mul_pd(a, scalar_vec);
            _mm512_storeu_pd(&A[i], a);
        }
    }
    else if constexpr (std::is_integral_v<data_type>)
    {
        if constexpr (sizeof(data_type) == 4) // 32-bit integers
        {
            __m512i scalar_vec = _mm512_set1_epi32(scalor);
            for (; i + 16 <= shape; i += 16)
            {
                __m512i a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
                a = _mm512_mullo_epi32(a, scalar_vec);
                _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), a);
            }
        }
        else if constexpr (sizeof(data_type) == 8) // 64-bit integers
        {
            __m512i scalar_vec = _mm512_set1_epi64(scalor);
            for (; i + 8 <= shape; i += 8)
            {
                __m512i a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
                a = _mm512_mullo_epi64(a, scalar_vec);
                _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), a);
            }
        }
    }
    // Process remaining elements
    for (; i < shape; i++)
    {
        A[i] *= scalor;
    }
}

#if 0  // side protector
template <typename data_type>
void simd_elem_div(data_type *A, size_t shape, const data_type &scalor)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        __m512 scalar_vec = _mm512_set1_ps(scalor);
        for (; i + 16 <= shape; i += 16)
        {
            __m512 a = _mm512_loadu_ps(&A[i]);
            a = _mm512_div_ps(a, scalar_vec);
            _mm512_storeu_ps(&A[i], a);
        }
    }
    else if constexpr (std::is_same_v<data_type, double>)
    {
        __m512d scalar_vec = _mm512_set1_pd(scalor);
        for (; i + 8 <= shape; i += 8)
        {
            __m512d a = _mm512_loadu_pd(&A[i]);
            a = _mm512_div_pd(a, scalar_vec);
            _mm512_storeu_pd(&A[i], a);
        }
    }
    else if constexpr (std::is_integral_v<data_type>)
    {
        using int_type = std::conditional_t<(sizeof(data_type) == 8), __m512i, __m512i>;
        int_type scalar_vec = _mm512_set1_epi32(scalor); // Assuming 32-bit integers
        for (; i + 16 <= shape; i += 16)
        {
            int_type a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
            a = _mm512_div_epi32(a, scalar_vec); // Note: AVX-512 does not have integer division, this is just a placeholder
            _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), a);
        }
    }
    // Process remaining elements
    for (; i < shape; i++)
    {
        A[i] /= scalor;
    }
}
#endif // side protector

#endif // protection header block
```

[[header.hpp]]
