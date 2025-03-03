#ifndef NUMPY_HPP
#define NUMPY_HPP
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>

/*
    // index
    + for matrix addition
    * with scalor for matrix sub with scalor
    * with matrix for matrix multiplication
    / for matrix division with scalor
    - for matrix addstract
    transpose() for transpose matrix
    power() for element wise power
    element_wise_multiplication() for element wise multiplication
    element_wise_division() for element wise division
    sum_all_elements() for sum all elements in matrix
    trace() for trace of matrix
    reshape_matrix() for reshape matrix
    rank() for rank of matrix
    inverse_matrix() for inverse matrix
    size_matrix() for size of matrix(rows * collom)
    deter() for determinant of matrix
    kronecker_product() for kronecker product of matrix

*/
namespace numpy
{
    template <typename data_type>
    class ndarray
    {
    private:
        std::vector<std::vector<data_type>> data;
        size_t rows, collom;

    public:
        ndarray(const data_type &r, const data_type &c) : collom(c), rows(r), data(r, std::vector<data_type>(c, 0)) {};
        ndarray(const std::vector<std::vector<data_type>> &d) : data(d), rows(d.size()), collom(d[0].size()) {};
        // use getter and setter for access data in private field
        ndarray<data_type> getter() const
        {
            return *this;
        }
        void setter(const ndarray<data_type> &nd)
        {
            rows = nd.rows;
            collom = nd.collom;
            data = nd.data;
        }
        // for operator overloading
        friend std::ostream &operator<<(std::ostream &os, const ndarray<data_type> &nd)
        {
            for (auto &i : nd.data)
            {
                for (auto &j : i)
                    os << j << " ";
                os << "\n";
            }
            return os;
        }
        friend std::istream &operator>>(std::istream &is, ndarray<data_type> &nd)
        {
            for (size_t i = 0; i < nd.rows; i++)
                for (size_t j = 0; j < nd.collom; j++)
                    is >> nd.data[i][j];
            return is;
        }
        std::vector<data_type> &operator[](const size_t &index)
        {
            if (index >= rows)
                throw std::runtime_error("index out of range");
            return data[index];
        }
        ndarray<data_type> &operator=(const ndarray<data_type> &nd)
        {
            rows = nd.rows;
            collom = nd.collom;
            data = nd.data;
            return *this;
        }
        ndarray<data_type> operator+(const ndarray<data_type> &nd)
        {
            if (rows != nd.rows && collom != nd.collom)
            {
                throw std::runtime_error("dimension error");
            }
            else
            {
                ndarray answer(rows, collom);
                for (size_t i = 0; i < rows; i++)
                {
                    for (size_t j = 0; j < collom; j++)
                    {
                        answer.data[i][j] += data[i][j] + nd.data[i][j];
                    }
                }
                return answer;
            }
        }
        ndarray<data_type> operator-(const ndarray<data_type> &nd)
        {
            if (rows != nd.rows && collom != nd.collom)
            {
                throw std::runtime_error("dimension error");
            }
            else
            {
                ndarray answer(rows, collom);
                for (size_t i = 0; i < rows; i++)
                {
                    for (size_t j = 0; j < collom; j++)
                    {
                        answer.data[i][j] += data[i][j] - nd.data[i][j];
                    }
                }
                return answer;
            }
        }
        ndarray<data_type> operator*(const data_type &scalor)
        {
            ndarray answer(rows, collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < collom; j++)
                {
                    answer.data[i][j] += data[i][j] * scalor;
                }
            }
            return answer;
        }
        ndarray<data_type> operator/(const data_type &scalor)
        {
            ndarray answer(rows, collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < collom; j++)
                {
                    answer.data[i][j] += data[i][j] / scalor;
                }
            }
            return answer;
        }
        ndarray<data_type> operator*(const ndarray &nd)
        {
            if (collom != nd.rows)
            {
                throw std::runtime_error("dimension error...");
            }
            else
            {
                ndarray answer(rows, nd.collom);
                for (size_t i = 0; i < rows; i++)
                {
                    for (size_t j = 0; j < nd.collom; j++)
                    {
                        for (size_t k = 0; k < collom; k++)
                        {
                            answer.data[i][j] += data[i][k] * nd.data[k][j];
                        }
                    }
                }
                return answer;
            }
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
        data_type size_matrix() const;
        // 0 for get rows and 1 for get collom
        data_type size_matrix(const bool &dimension_choice) const;
        data_type deter() const;
        ndarray<data_type> kronecker_product(const ndarray<data_type> &nd);
        // specs_algo in file specs_algo.hpp
    };
}

#endif