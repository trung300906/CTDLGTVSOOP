#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <immintrin.h> // AVX2
#include <chrono>

void simd_add(const int *A, const int *B, int *C, size_t n)
{
    size_t i = 0;
    for (; i + 8 <= n; i += 8) // Xử lý 8 phần tử cùng lúc
    {
        __m256i a = _mm256_loadu_si256((__m256i *)&A[i]);
        __m256i b = _mm256_loadu_si256((__m256i *)&B[i]);
        __m256i c = _mm256_add_epi32(a, b);
        _mm256_storeu_si256((__m256i *)&C[i], c);
    }

    // Xử lý phần dư (nếu không chia hết cho 8)
    for (; i < n; i++)
        C[i] = A[i] + B[i];
}

int main()
{
    size_t n = 1000000000; // 10 triệu phần tử
    std::vector<int> A(n, 1), B(n, 2), C(n);

    auto start = std::chrono::high_resolution_clock::now();
    std::transform(std::execution::par_unseq, A.begin(), A.end(), B.begin(), C.begin(),
                   [&](int a, int b)
                   {
                       return a + b; // Sử dụng SIMD bên trong (tối ưu bởi trình biên dịch)
                   });
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "std::transform + par_unseq: " << std::chrono::duration<double>(end - start).count() << "s\n";

    start = std::chrono::high_resolution_clock::now();
    simd_add(A.data(), B.data(), C.data(), n); // Dùng Intrinsics + SIMD
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Intrinsics SIMD: " << std::chrono::duration<double>(end - start).count() << "s\n";
}
