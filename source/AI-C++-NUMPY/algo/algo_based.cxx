#include "numpy.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>

namespace numpy
{
    // Explicit instantiation cho các kiểu cần dùng:
    template class ndarray<int>;
    template class ndarray<double>;
    template class ndarray<float>;
    template class ndarray<long>;
    template class ndarray<long long>;
    template class ndarray<unsigned>;
    template class ndarray<unsigned long>;
    template class ndarray<unsigned long long>; // C++11

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
    ndarray<data_type> ndarray<data_type>::power(const data_type &exponent)
    {
        if (rows == 0 || collom == 0)
        {
            throw std::runtime_error("Cannot apply power to an empty matrix.");
        }

        ndarray<data_type> answer(rows, collom);
        for (size_t i = 0; i < rows; i++)
        {
            std::transform(data[i].begin(), data[i].end(), answer.data[i].begin(), [exponent](data_type x)
                           { return std::pow(x, exponent); });
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
    data_type ndarray<data_type>::sum_all_elements() const
    {
        return std::accumulate(data.begin(), data.end(), 0.0, [](double sum, const std::vector<data_type> &row)
                               { return sum + std::accumulate(row.begin(), row.end(), 0.0); });
    }

    template <typename data_type>
    data_type ndarray<data_type>::trace()
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
    double ndarray<data_type>::deter() const
    {
        size_t n = data.size();

        // Kiểm tra ma trận có phải là ma trận vuông không
        for (const auto &row : data)
            if (row.size() != n)
                throw std::runtime_error("Ma trận phải là ma trận vuông.");

        // Ép kiểu ma trận sang double để tránh lỗi chia số nguyên
        std::vector<std::vector<double>> A(n, std::vector<double>(n));
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                A[i][j] = static_cast<double>(data[i][j]);

        double det = 1.0;

        for (size_t i = 0; i < n; i++)
        {
            size_t pivot = i;

            // Tìm phần tử chính (pivot)
            while (pivot < n && std::abs(A[pivot][i]) < 1e-9) // Kiểm tra gần bằng 0
                pivot++;

            // Nếu không tìm được phần tử khác 0, định thức = 0
            if (pivot == n)
                return static_cast<data_type>(0);

            // Hoán đổi dòng nếu cần
            if (pivot != i)
            {
                std::swap(A[i], A[pivot]);
                det = -det;
            }

            // Nhân vào định thức giá trị phần tử chéo chính
            det *= A[i][i];

            // Chia hàng hiện tại cho phần tử chéo chính
            for (size_t j = i + 1; j < n; j++)
                A[i][j] /= A[i][i];

            // Loại bỏ cột dưới hàng i
            for (size_t j = i + 1; j < n; j++)
                for (size_t k = i + 1; k < n; k++)
                    A[j][k] -= A[j][i] * A[i][k];
        }

        return (det);
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::adj()
    {
        if (rows != collom)
            throw std::runtime_error("Ma trận phải là ma trận vuông.");

        ndarray<data_type> cofactor_matrix(rows, collom);

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                // Tạo ma trận con bằng cách bỏ hàng i và cột j
                ndarray<data_type> temp(rows - 1, collom - 1);
                size_t sub_row = 0, sub_col;

                for (size_t k = 0; k < rows; k++)
                {
                    if (k == i)
                        continue; // Bỏ hàng i
                    sub_col = 0;
                    for (size_t l = 0; l < collom; l++)
                    {
                        if (l == j)
                            continue; // Bỏ cột j
                        temp.data[sub_row][sub_col] = data[k][l];
                        sub_col++;
                    }
                    sub_row++;
                }

                // Tính phần tử cofactor
                cofactor_matrix.data[i][j] = temp.deter() * (((i + j) % 2 == 0) ? 1 : -1);
            }
        }

        return cofactor_matrix.transpose();
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