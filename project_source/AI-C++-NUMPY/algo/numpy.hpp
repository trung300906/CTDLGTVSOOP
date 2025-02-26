#ifndef NUMPY_HPP
#define NUMPY_HPP
#include <vector>
#include <iostream>
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
    class ndarray
    {
    private:
        std::vector<std::vector<double>> data;
        size_t rows, collom;

    public:
        ndarray(const size_t &r, const size_t &c) : collom(c), rows(r), data(r, std::vector<double>(c, 0)) {};
        ndarray(const std::vector<std::vector<double>> &d) : data(d), rows(d.size()), collom(d[0].size()) {};
        // use getter and setter for access data in private field

        // for print matrix
        friend std::ostream &operator<<(std::ostream &os, const ndarray &nd)
        {
            for (auto &i : nd.data)
            {
                for (auto &j : i)
                    os << j << " ";
                os << std::endl;
            }
            return os;
        }
        friend std::istream &operator>>(std::istream &is, ndarray &nd)
        {
            for (int i = 0; i < nd.rows; i++)
            {
                for (int j = 0; j < nd.collom; j++)
                {
                    is >> nd.data[i][j];
                }
            }
            return is;
        }
        std::vector<double> &operator[](const int &index)
        {
            if (index >= rows)
                throw std::runtime_error("index out of range");
            return data[index];
        }
        ndarray operator=(const ndarray &nd)
        {
            rows = nd.rows;
            collom = nd.collom;
            data = nd.data;
            return *this;
        }
        ndarray operator+(const ndarray &nd)
        {
            if (rows != nd.rows && collom != nd.collom)
            {
                throw std::runtime_error("dimension error");
            }
            else
            {
                ndarray answer(rows, collom);
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < collom; j++)
                    {
                        answer.data[i][j] += data[i][j] + nd.data[i][j];
                    }
                }
                return answer;
            }
        }
        ndarray operator-(const ndarray &nd)
        {
            if (rows != nd.rows && collom != nd.collom)
            {
                throw std::runtime_error("dimension error");
            }
            else
            {
                ndarray answer(rows, collom);
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < collom; j++)
                    {
                        answer.data[i][j] += data[i][j] - nd.data[i][j];
                    }
                }
                return answer;
            }
        }
        ndarray operator*(const double &scalor)
        {
            ndarray answer(rows, collom);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < collom; j++)
                {
                    answer.data[i][j] += data[i][j] * scalor;
                }
            }
            return answer;
        }
        ndarray operator/(const double &scalor)
        {
            ndarray answer(rows, collom);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < collom; j++)
                {
                    answer.data[i][j] += data[i][j] / scalor;
                }
            }
            return answer;
        }
        ndarray operator*(const ndarray &nd)
        {
            if (collom != nd.rows)
            {
                throw std::runtime_error("dimension error...");
            }
            else
            {
                ndarray answer(rows, nd.collom);
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < nd.collom; j++)
                    {
                        for (int k = 0; k < collom; k++)
                        {
                            answer.data[i][j] += data[i][k] * nd.data[k][j];
                        }
                    }
                }
                return answer;
            }
        }

        // hearder function
        ndarray transpose();
        ndarray power(const double &exponent);
        ndarray element_wise_multiplication(const ndarray &nd);
        ndarray element_wise_division(const ndarray &nd);
        double sum_all_elements() const;
        double trace();
        ndarray reshape_matrix(const size_t &new_rows, const size_t &new_collom);
        int rank();
        ndarray inverse_matrix();
        // 0 for get rows and 1 for get collom
        double size_matrix() const;
        double deter() const;
        ndarray kronecker_product(const ndarray &nd);
    };

#if 0
#define MATMUL @
    ndarray operator MATMUL(const ndarray &a, const ndarray &b)
    {
        if (a.collom !-b.rows)
        {
            throw std::runtime_error("dimension error...");
        }
        else
        {
            ndarray answer(a.rows, b.collom);
            for (int i = 0; i < a.rows; i++)
            {
                for (int j = 0; j < b.collom; j++)
                {
                    for (int k = 0; k < a.collom; k++)
                    {
                        answer.data[i][j] += a.data[i][k] * b.data[k][j];
                    }
                }
            }
            return answer;
        }
    }
#endif
}

#endif