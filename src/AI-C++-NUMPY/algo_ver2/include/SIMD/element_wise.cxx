#include "simd_index.hpp"

template <typename data_type>
void simd_elem_add(data_type *A, size_t shape, const data_type &scalor)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        __m512 scalar_vec = _mm512_set1_ps(scalor); // Broadcast scalar to all elements of the vector
        for (; i + 16 <= shape; i += 16)
        {
            __m512 a = _mm512_loadu_ps(&A[i]); // Load 16 floats from memory
            a = _mm512_add_ps(a, scalar_vec);  // Perform element-wise addition
            _mm512_storeu_ps(&A[i], a);        // Store the result back to memory
        }
    }
    else if constexpr (std::is_same_v<data_type, double>)
    {
        __m512d scalar_vec = _mm512_set1_pd(scalor); // Broadcast scalar to all elements of the vector
        for (; i + 8 <= shape; i += 8)
        {
            __m512d a = _mm512_loadu_pd(&A[i]); // Load 8 doubles from memory
            a = _mm512_add_pd(a, scalar_vec);   // Perform element-wise addition
            _mm512_storeu_pd(&A[i], a);         // Store the result back to memory
        }
    }
    else if constexpr (std::is_integral_v<data_type>)
    {
        if constexpr (sizeof(data_type) == 4) // 32-bit integers
        {
            __m512i scalar_vec = _mm512_set1_epi32(scalor); // Broadcast scalar to all elements of the vector
            for (; i + 16 <= shape; i += 16)
            {
                __m512i a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i])); // Load 16 integers
                a = _mm512_add_epi32(a, scalar_vec);                                      // Perform element-wise addition
                _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), a);               // Store the result back to memory
            }
        }
        else if constexpr (sizeof(data_type) == 8) // 64-bit integers
        {
            __m512i scalar_vec = _mm512_set1_epi64(scalor); // Broadcast scalar to all elements of the vector
            for (; i + 8 <= shape; i += 8)
            {
                __m512i a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i])); // Load 8 integers
                a = _mm512_add_epi64(a, scalar_vec);                                      // Perform element-wise addition
                _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), a);               // Store the result back to memory
            }
        }
    }
    // Process remaining elements
    for (; i < shape; i++)
    {
        A[i] += scalor;
    }
}

template <typename data_type>
void simd_elem_sub(data_type *A, size_t shape, const data_type &scalor)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        __m512 scalar_vec = _mm512_set1_ps(scalor);
        for (; i + 16 <= shape; i += 16)
        {
            __m512 a = _mm512_loadu_ps(&A[i]);
            a = _mm512_sub_ps(a, scalar_vec);
            _mm512_storeu_ps(&A[i], a);
        }
    }
    else if constexpr (std::is_same_v<data_type, double>)
    {
        __m512d scalar_vec = _mm512_set1_pd(scalor);
        for (; i + 8 <= shape; i += 8)
        {
            __m512d a = _mm512_loadu_pd(&A[i]);
            a = _mm512_sub_pd(a, scalar_vec);
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
                a = _mm512_sub_epi32(a, scalar_vec);
                _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), a);
            }
        }
        else if constexpr (sizeof(data_type) == 8) // 64-bit integers
        {
            __m512i scalar_vec = _mm512_set1_epi64(scalor);
            for (; i + 8 <= shape; i += 8)
            {
                __m512i a = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
                a = _mm512_sub_epi64(a, scalar_vec);
                _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), a);
            }
        }
    }
    // Process remaining elements
    for (; i < shape; i++)
    {
        A[i] -= scalor;
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
        if constexpr (sizeof(data_type) == 4) // 32-bit integers
        {
            for (; i + 16 <= shape; i += 16)
            {
                __m512i vec = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
                alignas(64) data_type temp[16];
                _mm512_store_si512(reinterpret_cast<__m512i *>(temp), vec);
                for (size_t j = 0; j < 16; j++)
                {
                    temp[j] /= scalor;
                }
                vec = _mm512_load_si512(reinterpret_cast<const __m512i *>(temp));
                _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), vec);
            }
        }
        else if constexpr (sizeof(data_type) == 8) // 64-bit integers
        {
            for (; i + 8 <= shape; i += 8)
            {
                __m512i vec = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&A[i]));
                alignas(64) data_type temp[8];
                _mm512_store_si512(reinterpret_cast<__m512i *>(temp), vec);
                for (size_t j = 0; j < 8; j++)
                {
                    temp[j] /= scalor;
                }
                vec = _mm512_load_si512(reinterpret_cast<const __m512i *>(temp));
                _mm512_storeu_si512(reinterpret_cast<__m512i *>(&A[i]), vec);
            }
        }
    }
    // Xử lý các phần tử còn lại
    for (; i < shape; i++)
    {
        A[i] /= scalor;
    }
}

template <typename data_type>
void simd_power(data_type *A, size_t shape, const data_type &scalor)
{
    size_t i = 0;
    if constexpr (std::is_same_v<data_type, float>)
    {
        for (; i + 16 <= shape; i += 16)
        {
            // For floating point, we use exp(log(x) * power)
            __m512 a = _mm512_loadu_ps(&A[i]);
            // Handle special cases: negative numbers and zero
            __mmask16 zero_mask = _mm512_cmpeq_ps_mask(a, _mm512_setzero_ps());
            __mmask16 neg_mask = _mm512_cmplt_ps_mask(a, _mm512_setzero_ps());

            // Take log of absolute values
            __m512 log_a = _mm512_log_ps(_mm512_abs_ps(a));
            __m512 scalar_vec = _mm512_set1_ps(scalor);
            __m512 mul = _mm512_mul_ps(log_a, scalar_vec);
            __m512 result = _mm512_exp_ps(mul);

            // Handle negative numbers if exponent is integer
            if (std::floor(scalor) == scalor)
            {
                // For negative numbers, check if power is odd or even
                if (std::fmod(scalor, 2.0) == 1.0)
                {
                    // For odd power, preserve the sign
                    result = _mm512_mask_mul_ps(result, neg_mask, result, _mm512_set1_ps(-1.0f));
                }
            }

            // Zero raised to any power (except 0) is 0
            result = _mm512_mask_blend_ps(zero_mask, result, _mm512_setzero_ps());

            // Zero raised to power 0 is 1 (mathematical convention)
            if (scalor == 0.0)
            {
                result = _mm512_mask_blend_ps(zero_mask, result, _mm512_set1_ps(1.0f));
            }

            _mm512_storeu_ps(&A[i], result);
        }
    }
    else if constexpr (std::is_same_v<data_type, double>)
    {
        for (; i + 8 <= shape; i += 8)
        {
            // For floating point, we use exp(log(x) * power)
            __m512d a = _mm512_loadu_pd(&A[i]);
            // Handle special cases: negative numbers and zero
            __mmask8 zero_mask = _mm512_cmpeq_pd_mask(a, _mm512_setzero_pd());
            __mmask8 neg_mask = _mm512_cmplt_pd_mask(a, _mm512_setzero_pd());

            // Take log of absolute values
            __m512d log_a = _mm512_log_pd(_mm512_abs_pd(a));
            __m512d scalar_vec = _mm512_set1_pd(scalor);
            __m512d mul = _mm512_mul_pd(log_a, scalar_vec);
            __m512d result = _mm512_exp_pd(mul);

            // Handle negative numbers if exponent is integer
            if (std::floor(scalor) == scalor)
            {
                // For negative numbers, check if power is odd or even
                if (std::fmod(scalor, 2.0) == 1.0)
                {
                    // For odd power, preserve the sign
                    result = _mm512_mask_mul_pd(result, neg_mask, result, _mm512_set1_pd(-1.0));
                }
            }

            // Zero raised to any power (except 0) is 0
            result = _mm512_mask_blend_pd(zero_mask, result, _mm512_setzero_pd());

            // Zero raised to power 0 is 1 (mathematical convention)
            if (scalor == 0.0)
            {
                result = _mm512_mask_blend_pd(zero_mask, result, _mm512_set1_pd(1.0));
            }

            _mm512_storeu_pd(&A[i], result);
        }
    }
    else if constexpr (std::is_integral_v<data_type>)
    {
        // For integer types, we need to use a different approach
        // We'll use scalar operations for integer powers
        if (scalor >= 0 && scalor <= 20) // Limit to avoid overflow
        {
            for (; i < shape; i++)
            {
                data_type result = 1;
                data_type base = A[i];
                data_type exponent = scalor;

                // Exponentiation by squaring
                while (exponent > 0)
                {
                    if (exponent % 2 == 1)
                    {
                        result *= base;
                    }
                    base *= base;
                    exponent /= 2;
                }

                A[i] = result;
            }
            return; // Early return to avoid the second loop
        }
    }
    // Process remaining elements or handle all elements for integer types
    for (; i < shape; i++)
    {
        if constexpr (std::is_same_v<data_type, float>)
            A[i] = __builtin_powf(A[i], scalor);
        else if constexpr (std::is_same_v<data_type, double>)
            A[i] = __builtin_pow(A[i], scalor);
        else if constexpr (std::is_integral_v<data_type>)
            A[i] = static_cast<data_type>(__builtin_pow(static_cast<double>(A[i]), static_cast<double>(scalor)));
    }
}