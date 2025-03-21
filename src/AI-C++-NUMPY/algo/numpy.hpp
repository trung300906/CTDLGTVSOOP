#ifndef NUMPY_HPP
#define NUMPY_HPP
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>
namespace numpy
{
    template <typename data_type>
    class ndarray
    {
    protected:
        std::vector<std::vector<data_type>> data;
        size_t rows, collom;

    public:
        ndarray(const data_type &r, const data_type &c) : collom(c), rows(r), data(r, std::vector<data_type>(c, 0)) {};
        ndarray(const std::vector<std::vector<data_type>> &d) : data(d), rows(d.size()), collom(d[0].size()) {};
        // use getter and setter for access data in private field
        ndarray<data_type> getter() const;
        void setter(const ndarray<data_type> &nd);

        // for operator overloading
        friend std::ostream &operator<<(std::ostream &os, const ndarray<data_type> &nd)
        {
            for (size_t i = 0; i < nd.rows; i++)
            {
                for (size_t j = 0; j < nd.collom; j++)
                {
                    os << nd.data[i][j] << " ";
                }
                os << std::endl;
            }
            return os;
        }
        friend std::istream &operator>>(std::istream &is, ndarray<data_type> &nd)
        {
            for (size_t i = 0; i < nd.rows; i++)
            {
                for (size_t j = 0; j < nd.collom; j++)
                {
                    is >> nd.data[i][j];
                }
            }
            return is;
        }

        std::vector<data_type> &operator[](const size_t &index)
        {
            return data[index];
        }
        const std::vector<data_type> &operator[](const size_t &index) const
        {
            return data[index];
        }
        ndarray<data_type> &operator=(const ndarray<data_type> &nd)
        {
            data = nd.data;
            rows = nd.rows;
            collom = nd.collom;
            return *this;
        }
        ndarray<data_type> operator+(const ndarray<data_type> &nd)
        {
            if (rows != nd.rows || collom != nd.collom)
            {
                throw std::invalid_argument("Matrix size is not the same");
            }
            ndarray<data_type> result(rows, collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < collom; j++)
                {
                    result.data[i][j] = data[i][j] + nd.data[i][j];
                }
            }
            return result;
        }
        ndarray<data_type> operator-(const ndarray<data_type> &nd)
        {
            if (rows != nd.rows || collom != nd.collom)
            {
                throw std::invalid_argument("Matrix size is not the same");
            }
            ndarray<data_type> result(rows, collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < collom; j++)
                {
                    result.data[i][j] = data[i][j] - nd.data[i][j];
                }
            }
            return result;
        }
        ndarray<data_type> operator*(const data_type &scalor)
        {
            ndarray<data_type> result(rows, collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < collom; j++)
                {
                    result.data[i][j] = data[i][j] * scalor;
                }
            }
            return result;
        }
        ndarray<data_type> operator/(const data_type &scalor)
        {
            ndarray<data_type> result(rows, collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < collom; j++)
                {
                    result.data[i][j] = data[i][j] / scalor;
                }
            }
            return result;
        }

        ndarray<data_type> operator*(const ndarray<data_type> &nd)
        {
            if (collom != nd.rows)
            {
                throw std::invalid_argument("Matrix size is not the same");
            }
            ndarray<data_type> result(rows, nd.collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < nd.collom; j++)
                {
                    for (size_t k = 0; k < collom; k++)
                    {
                        result.data[i][j] += data[i][k] * nd.data[k][j];
                    }
                }
            }
            return result;
        }

        // hearder function
        ndarray<data_type> transpose();
        ndarray<data_type> power(const data_type &exponent);
        ndarray<data_type> element_wise_multiplication(const ndarray<data_type> &nd);
        ndarray<data_type> element_wise_division(const ndarray<data_type> &nd);
        data_type sum_all_elements() const;
        data_type trace();
        ndarray<data_type> reshape_matrix(const size_t &new_rows, const size_t &new_collom);
        int rank();
        ndarray<data_type> inverse_matrix();
        ndarray<data_type> adj();
        data_type size_matrix() const;
        // 0 for get rows and 1 for get collom
        data_type size_matrix(const bool &dimension_choice) const;
        double deter() const;
        ndarray<data_type> kronecker_product(const ndarray<data_type> &nd);
    };
}

#endif