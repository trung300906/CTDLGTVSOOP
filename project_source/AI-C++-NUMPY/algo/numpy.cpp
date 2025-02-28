#include "numpy.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>

namespace numpy
{
    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::transpose()
    {
        ndarray<data_type> answer(collom, rows);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                answer.data[j][i] = data[i][j];
            }
        }
        return answer;
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::power(const double &exponent)
    {
        ndarray<data_type> answer(rows, collom);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                answer.data[i][j] = pow(data[i][j], exponent);
            }
        }
        return answer;
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::element_wise_multiplication(const ndarray<data_type> &nd)
    {
        if (rows != nd.rows || collom != nd.collom)
        {
            throw std::runtime_error("dimension error");
        }
        else
        {
            ndarray<data_type> answer(rows, collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < collom; j++)
                {
                    answer.data[i][j] = data[i][j] * nd.data[i][j];
                }
            }
            return answer;
        }
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::element_wise_division(const ndarray<data_type> &nd)
    {
        if (rows != nd.rows && collom != nd.collom)
        {
            throw std::runtime_error("dimension error");
        }
        else
        {
            ndarray<data_type> answer(rows, collom);
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < collom; j++)
                {
                    if (nd.data[i][j] == 0)
                        throw std::runtime_error("division by zero");
                    answer.data[i][j] = data[i][j] / nd.data[i][j];
                }
            }
            return answer;
        }
    }

    template <typename data_type>
    double ndarray<data_type>::sum_all_elements() const
    {
        return std::accumulate(data.begin(), data.end(), 0.0, [](double sum, const std::vector<data_type> &row)
                               { return sum + std::accumulate(row.begin(), row.end(), 0.0); });
    }

    template <typename data_type>
    double ndarray<data_type>::trace()
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

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::reshape_matrix(const size_t &new_rows, const size_t &new_collom)
    {
        size_t total_elements = rows * collom;
        if (new_rows * new_collom != total_elements)
            throw std::runtime_error("Số phần tử không khớp.");
        std::vector<double> flat;
        for (int i = 0; i < rows; i++)
            flat.insert(flat.end(), data[i].begin(), data[i].end());
        ndarray<data_type> result(new_rows, new_collom);
        int index = 0;
        for (size_t i = 0; i < new_rows; i++)
        {
            for (size_t j = 0; j < new_collom; j++)
            {
                result.data[i][j] = flat[index++];
            }
        }
        return result;
    }

    template <typename data_type>
    int ndarray<data_type>::rank()
    {
        int rank = 0;
        for (size_t i = 0; i < rows; i++)
        {
            bool non_zero = false;
            for (size_t j = 0; j < collom; j++)
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

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::inverse_matrix()
    {
        int n = rows;
        for (const auto &row : data)
        {
            if (row.size() != n)
            {
                throw std::runtime_error("Ma trận phải là ma trận vuông.");
            }
        }
        std::vector<std::vector<data_type>> augmented_matrix(n, std::vector<data_type>(2 * n, 0));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                augmented_matrix[i][j] = data[i][j];
            }
            augmented_matrix[i][i + n] = 1;
        }
        for (size_t i = 0; i < n; i++)
        {
            if (augmented_matrix[i][i] == 0)
            {
                int row = i + 1;
                while (row < n && augmented_matrix[row][i] == 0)
                    row++;
                if (row == n)
                    throw std::runtime_error("Ma trận không khả nghịch.");
                for (size_t j = 0; j < 2 * n; j++)
                {
                    std::swap(augmented_matrix[i][j], augmented_matrix[row][j]);
                }
            }
            double temp = augmented_matrix[i][i];
            for (size_t j = 0; j < 2 * n; j++)
            {
                augmented_matrix[i][j] /= temp;
            }
            for (size_t j = 0; j < n; j++)
            {
                if (i != j)
                {
                    double temp = augmented_matrix[j][i];
                    for (size_t k = 0; k < 2 * n; k++)
                    {
                        augmented_matrix[j][k] -= temp * augmented_matrix[i][k];
                    }
                }
            }
        }
        std::vector<std::vector<data_type>> inverse_matrix(n, std::vector<data_type>(n, 0));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                inverse_matrix[i][j] = augmented_matrix[i][j + n];
            }
        }
        return inverse_matrix;
    }

    template <typename data_type>
    data_type ndarray<data_type>::size_matrix() const
    {
        return rows * collom;
    }

    template <typename data_type>
    data_type ndarray<data_type>::size_matrix(const bool &dimension_Choice) const
    {
        if (dimension_Choice == 0)
        {
            return rows;
        }
        else if (dimension_Choice == 1)
        {
            return collom;
        }
        else
        {
            throw std::runtime_error("dimension error");
        }
    }

    template <typename data_type>
    data_type ndarray<data_type>::deter() const
    {
        size_t n = data.size();
        for (const auto &row : data)
            if (row.size() != n)
                throw std::runtime_error("Ma trận phải là ma trận vuông.");

        std::vector<std::vector<data_type>> A = data; // Sao chép để không làm thay đổi dữ liệu gốc
        double det = 1;

        for (size_t i = 0; i < n; i++)
        {
            size_t pivot = i;
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
            for (size_t j = i + 1; j < n; j++)
                A[i][j] /= A[i][i];
            for (size_t j = i + 1; j < n; j++)
                for (size_t k = i + 1; k < n; k++)
                    A[j][k] -= A[j][i] * A[i][k];
        }
        return det;
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::kronecker_product(const ndarray<data_type> &nd)
    {
        size_t m = rows;
        size_t n = collom;
        size_t p = nd.rows;
        size_t q = nd.collom;
        ndarray result(m * p, n * q);
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                for (size_t k = 0; k < p; k++)
                {
                    for (size_t l = 0; l < q; l++)
                    {
                        result.data[i * p + k][j * q + l] = data[i][j] * nd.data[k][l];
                    }
                }
            }
        }
        return result;
    }
}