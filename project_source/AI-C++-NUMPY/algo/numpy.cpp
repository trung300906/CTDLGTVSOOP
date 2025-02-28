#include "numpy.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>

namespace numpy
{
    ndarray ndarray::transpose()
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
    ndarray ndarray::power(const double &exponent)
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
    ndarray ndarray::element_wise_multiplication(const ndarray &nd)
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
    ndarray ndarray::element_wise_division(const ndarray &nd)
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
    double ndarray::sum_all_elements() const
    {
        return std::accumulate(data.begin(), data.end(), 0.0, [](double sum, const std::vector<double> &row)
                               { return sum + std::accumulate(row.begin(), row.end(), 0.0); });
    }
    double ndarray::trace()
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
    ndarray ndarray::reshape_matrix(const size_t &new_rows, const size_t &new_collom)
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
    int ndarray::rank()
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
    ndarray ndarray::inverse_matrix()
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
    double ndarray::size_matrix() const
    {
        return rows * collom;
    }
    double ndarray::size_matrix(const double &dimension_Choice) const
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
    double ndarray::deter() const
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
    ndarray ndarray::kronecker_product(const ndarray &nd)
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
}