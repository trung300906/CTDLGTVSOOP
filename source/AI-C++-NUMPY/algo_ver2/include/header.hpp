#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <vector>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <string>
#include <algorithm>
#include <execution>

// multi-thread
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <future>

// memory
#include <memory>      // smart pointers (unique_ptr, shared_ptr)
#include <cstdlib>     // malloc, free, aligned_alloc
#include <new>         // placement new
#include <mm_malloc.h> // _mm_malloc, _mm_free

// AVX
#include <immintrin.h> // AVX2
#include <xmmintrin.h> // SSE
#include <emmintrin.h> // SSE2
#include <pmmintrin.h> // SSE3
#include <smmintrin.h> // SSE4

// MATH
#include <cmath>   // C++ math functions
#include <numeric> // Accumulate, inner_product, etc.
#include <complex> // Complex numbers
#include <random>  // Random number generation

#endif