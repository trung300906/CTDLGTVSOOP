#ifndef NUMPY_HPP
#define NUMPY_HPP
#include <iostream>
#include <vector>
#include <cassert>
#include <initializer_list>

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
                assert(indices[i] < shape[i]);
                idx += indices[i] * strides[i];
            }
            return idx;
        }

        data_type &operator()(const std::initializer_list<size_t> &indices)
        {
            return data[Index(indices)];
        }
        const data_type &operator()(const std::initializer_list<size_t> &indices) const
        {
            return data[Index(indices)];
        }
    };
    // Hàm đệ quy để in mảng n chiều
    template <typename data_type>
    void print_recursive(std::ostream &out, const ndarray<data_type>& nd, std::vector<size_t>& indices, size_t dim) {
        if (dim == nd.shape.size()) {
            // Khi đã có chỉ số cho tất cả các chiều, in giá trị tại vị trí đó
            out << nd({indices.begin(), indices.end()});
            return;
        }
        
        out << "[";
        for (size_t i = 0; i < nd.shape[dim]; i++) {
            indices.push_back(i);
            print_recursive(out, nd, indices, dim + 1);
            indices.pop_back();
            if (i != nd.shape[dim] - 1)
                out << ", ";
        }
        out << "]";
    }

    // Overload operator<< cho ndarray
    template <typename data_type>
    std::ostream& operator<<(std::ostream &out, const ndarray<data_type>& nd) {
        std::vector<size_t> indices;
        print_recursive(out, nd, indices, 0);
        return out;
    }
}
#endif