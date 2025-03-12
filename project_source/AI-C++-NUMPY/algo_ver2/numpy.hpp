#ifndef NUMPY_HPP
#define NUMPY_HPP
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
    all things will store in 1D array, and because for that, it will be easy and  effecient for memory
    about index:
    just think from eazy way, if you have and 3D array, it's like a cube, and each layer is 2D array, and each row is 1D array
    and strides will store stride in 1D array raw, to access the next of layer, for example, if you have 3x4x5 array, the formula will be:
    shape = [3,4,5]
    strides[2] = 1 (alwasys 1 because this is the last layer, mean that no layer next to it to strides more, and every access in this layer will be like an 1D array)
    strides[1] = strides[2]*shape[2-1] = 1 * 5 = 5, mean that wanna acess layer, you must jump 5 element in 1D array
    strides[0] = strides[1]*shape[1-1] = 5 * 4 mean that wanna access next layer, you must jump 5*4 = 20 element in 1D array
    so, if you want to get value at (i, j, k), you just need to calculate index = i * stride[0] + j * stride[1] + k * stride[2]
    and if you want to get value at (i, j), you just need to calculate index = i * stride[0] + j * stride[1]
    and if you want to get value at (i), you just need to calculate index = i * stride[0]
*/
namespace numpy
{
    template <typename data_type>
    class ndarray
    {
    protected:
        std::vector<data_type> data; // 1D array data
        std::vector<size_t> shape;   // store shape of array(ex 3x4x5 mean 3D array with 3 layer, each layer has 4 row, and each row has 5 element)
        std::vector<size_t> strides; // store and calculate strides for each dimension

    public:
        ndarray(const std::vector<size_t> &shape_) : shape(shape_)
        {
            strides.resize(shape.size());
            size_t total = 1;
            for (int i = shape.size() - 1; i >= 0; --i)
            {
                strides[i] = total;
                total *= shape[i];
            }
            data.resize(total, 0);
        }

        // this function will outcome the index of things we need to access
        size_t Index(const std::vector<size_t> &indices) const
        {
            assert(indices.size() == shape.size());
            size_t idx = 0;
            for (size_t i = 0; i < indices.size(); i++)
            {
                assert(indices[i] <= shape[i]);
                idx += indices[i] * strides[i];
            }
            return idx;
        }

        // operator function
        data_type &operator()(const std::vector<size_t> &indices)
        {
            return data[Index(indices)];
        }
        const data_type &operator()(const std::vector<size_t> &indices) const
        {
            return data[Index(indices)];
        }
        friend std::ostream &operator<<(std::ostream &out, ndarray<data_type> &nd)
        {
            // Hàm đệ quy để in mảng n chiều
            std::function<void(std::vector<size_t> &, std::vector<size_t> &, size_t, size_t)> recursive;
            recursive = [&](std::vector<size_t> &index, std::vector<size_t> &path, size_t level = 0, size_t indent = 0)
            {
                if (level == index.size())
                {
                    out << std::string(indent, ' ') << "[";
                    out << nd(path);
                    out << "]\n";
                    return;
                }
                out << std::string(indent, ' ') << "[\n";
                for (size_t i = 0; i < index[level]; i++)
                {
                    path[level] = i;
                    recursive(index, path, level + 1, indent + 2);
                }
                out << std::string(indent, ' ') << "]\n";
            };
            std::vector<size_t> path(nd.shape.size(), 0);
            recursive(nd.shape, path, 0, 0);
            return out;
        }
        friend std::istream &operator>>(std::istream &input, ndarray<data_type> &nd)
        {
            std::function<void(std::vector<size_t> &, std::vector<size_t> &, size_t)> recursive;
            recursive = [&](std::vector<size_t> &index, std::vector<size_t> &path, size_t level = 0)
            {
                if (level == index.size())
                {
                    std::cout << "[";
                    for (auto &elem : path)
                        std::cout << elem + 1 << " ";
                    std::cout << "]: ";
                    input >> nd(path);
                    std::cout << "\n";
                    return;
                }
                for (size_t i = 0; i < index[level]; i++)
                {
                    path[level] = i;
                    recursive(index, path, level + 1);
                }
            };
            std::vector<size_t> path(nd.shape.size(), 0);
            recursive(nd.shape, path, 0);
            return input;
        }
        ndarray<data_type> operator=(const ndarray<data_type> &nd)
        {
            shape = nd.shape;
            strides = nd.strides;
            data = nd.data;
            return *this;
        }

        // need fix
        ndarray<data_type> operator+(const ndarray<data_type> &nd)
        {
            assert(nd.data.size() == data.size());
            assert(nd.shape == shape);
            assert(nd.strides == strides);
            ndarray<data_type> answer({shape});
            std::function<void(const data_type *A, const data_type *B, data_type *C, size_t n)> simd_add;
            simd_add = [&](const data_type *A, const data_type *B, data_type *C, size_t n)
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
            };
            simd_add(data.data(), nd.data.data(), answer.data.data(), data.size());
            return answer;
        }
        ndarray<data_type> operator-(const ndarray<data_type> &nd)
        {
            assert(nd.data.size() == data.size());
            assert(nd.shape == shape);
            assert(nd.strides == strides);
            ndarray<data_type> answer({shape});
            std::function<void(const data_type *A, const data_type *B, data_type *C, size_t n)> simd_add;
            simd_add = [&](const data_type *A, const data_type *B, data_type *C, size_t n)
            {
                size_t i = 0;
                for (; i + 8 <= n; i += 8) // Xử lý 8 phần tử cùng lúc
                {
                    __m256i a = _mm256_loadu_si256((__m256i *)&A[i]);
                    __m256i b = _mm256_loadu_si256((__m256i *)&B[i]);
                    __m256i c = _mm256_sub_epi32(a, b);
                    _mm256_storeu_si256((__m256i *)&C[i], c);
                }

                // Xử lý phần dư (nếu không chia hết cho 8)
                for (; i < n; i++)
                    C[i] = A[i] - B[i];
            };
            simd_add(data.data(), nd.data.data(), answer.data.data(), data.size());
            return answer;
        }
#if 0
        ndarray<data_type> operator*(const data_type &scalor)
        {
            
        }
        ndarray<data_type> operator/(const ndarray<data_type> &scalor)
        {
        }
#endif
    };
}
#endif