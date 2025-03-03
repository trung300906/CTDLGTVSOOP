#include <iostream>
#include <vector>
#include <cassert>
#include <initializer_list>

template <typename data_type>
class ndarray
{
protected:
    std::vector<data_type> data;
    std::vector<size_t> shape;
    std::vector<size_t> strides;

public:
    ndarray(const std::vector<size_t> &shape_) : shape(shape_)
    {
        strides.resize(shape.size());
        size_t total = 1;
        for (int i = shape.size() - 2; i >= 0; i--)
        {
            strides[i] = total;
            total *= shape[i];
        }
        data.resize(total);
    };
    size_t index(const std::vector<size_t> &indices) const
    {
        assert(indices.size() == shape.size());
        size_t idx = 0;
        for (int i = 0; i < indices.size(); i++)
        {
            idx += indices[i] * strides[i];
        }
        return idx;
    }
};
