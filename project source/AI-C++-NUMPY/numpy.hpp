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
        ndarray transpose()
        {
            ndarray answer(collom, rows);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < collom; j++)
                {
                    answer.data[j][i] = data[i][j];
                }
            }
            return answer;
        }
        ndarray power(const double &exponent)
        {
            ndarray answer(rows, collom);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < collom; j++)
                {
                    answer.data[i][j] = pow(data[i][j], exponent);
                }
            }
            return answer;
        }
        ndarray element_wise_multiplication(const ndarray &nd)
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
                        answer.data[i][j] = data[i][j] * nd.data[i][j];
                    }
                }
                return answer;
            }
        }
        ndarray element_wise_division(const ndarray &nd)
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
                        if (nd.data[i][j] == 0)
                            throw std::runtime_error("division by zero");
                        answer.data[i][j] = data[i][j] / nd.data[i][j];
                    }
                }
                return answer;
            }
        }
        double sum_all_elements() const
        {
            return std::accumulate(data.begin(), data.end(), 0.0, [](double sum, const std::vector<double> &row)
                                   { return sum + std::accumulate(row.begin(), row.end(), 0.0); });
        }
        double trace()
        {
            if (rows != collom)
                throw std::runtime_error("Ma trận phải là ma trận vuông.");
            double tr = 0;
            for (int i = 0; i < rows; i++)
            {
                tr += data[i][i];
            }
            return tr;
        }
        ndarray reshape_matrix(const size_t &new_rows, const size_t &new_collom)
        {
            size_t total_elements = rows * collom;
            if (new_rows * new_collom != total_elements)
                throw std::runtime_error("Số phần tử không khớp.");
            std::vector<double> flat;
            for (int i = 0; i < rows; i++)
                flat.insert(flat.end(), data[i].begin(), data[i].end());
            ndarray result(new_rows, new_collom);
            int index = 0;
            for (int i = 0; i < new_rows; i++)
            {
                for (int j = 0; j < new_collom; j++)
                {
                    result.data[i][j] = flat[index++];
                }
            }
            return result;
        }
        int rank()
        {
            int rank = 0;
            for (int i = 0; i < rows; i++)
            {
                bool non_zero = false;
                for (int j = 0; j < collom; j++)
                {
                    if (data[i][j] != 0)
                    {
                        non_zero = true;
                        break;
                    }
                }
                if (non_zero)
                    rank++;
            }
            return rank;
        }
        ndarray inverse_matrix()
        {
            int n = rows;
            for (const auto &row : data)
            {
                if (row.size() != n)
                {
                    throw std::runtime_error("Ma trận phải là ma trận vuông.");
                }
            }
            std::vector<std::vector<double>> augmented_matrix(n, std::vector<double>(2 * n, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    augmented_matrix[i][j] = data[i][j];
                }
                augmented_matrix[i][i + n] = 1;
            }
            for (int i = 0; i < n; i++)
            {
                if (augmented_matrix[i][i] == 0)
                {
                    int row = i + 1;
                    while (row < n && augmented_matrix[row][i] == 0)
                        row++;
                    if (row == n)
                        throw std::runtime_error("Ma trận không khả nghịch.");
                    for (int j = 0; j < 2 * n; j++)
                    {
                        std::swap(augmented_matrix[i][j], augmented_matrix[row][j]);
                    }
                }
                double temp = augmented_matrix[i][i];
                for (int j = 0; j < 2 * n; j++)
                {
                    augmented_matrix[i][j] /= temp;
                }
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        double temp = augmented_matrix[j][i];
                        for (int k = 0; k < 2 * n; k++)
                        {
                            augmented_matrix[j][k] -= temp * augmented_matrix[i][k];
                        }
                    }
                }
            }
            std::vector<std::vector<double>> inverse_matrix(n, std::vector<double>(n, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    inverse_matrix[i][j] = augmented_matrix[i][j + n];
                }
            }
            return inverse_matrix;
        }

        // 0 for get rows and 1 for get collom
        double size_matrix() const
        {
            return rows * collom;
        }

        double deter() const
        {
            int n = data.size();
            for (const auto &row : data)
                if (row.size() != n)
                    throw std::runtime_error("Ma trận phải là ma trận vuông.");

            std::vector<std::vector<double>> A = data; // Sao chép để không làm thay đổi dữ liệu gốc
            double det = 1;

            for (int i = 0; i < n; i++)
            {
                int pivot = i;
                while (pivot < n && A[pivot][i] == 0)
                    pivot++;
                if (pivot == n)
                    return 0;

                if (pivot != i)
                {
                    std::swap(A[i], A[pivot]);
                    det = -det;
                }

                det *= A[i][i];
                for (int j = i + 1; j < n; j++)
                    A[i][j] /= A[i][i];
                for (int j = i + 1; j < n; j++)
                    for (int k = i + 1; k < n; k++)
                        A[j][k] -= A[j][i] * A[i][k];
            }
            return det;
        }

        ndarray kronecker_product(const ndarray &nd)
        {
            size_t m = rows;
            size_t n = collom;
            size_t p = nd.rows;
            size_t q = nd.collom;
            ndarray result(m * p, n * q);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < p; k++)
                    {
                        for (int l = 0; l < q; l++)
                        {
                            result.data[i * p + k][j * q + l] = data[i][j] * nd.data[k][l];
                        }
                    }
                }
            }
            return result;
        }
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