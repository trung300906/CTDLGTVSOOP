#include "numpy.h"
#include "specs_algo.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <stdexcept>

namespace numpy
{
    template <typename data_type>
    double specs_algo<data_type>::mean()
    {
        double sum = 0;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                sum += data[i][j];
            }
        }
        return sum / (rows * collom);
    }
    template <typename data_type>
    double specs_algo<data_type>::variance()
    {
        double mean = this->mean();
        double sum = 0;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                sum += std::pow(data[i][j] - mean, 2);
            }
        }
        return sum / (rows * collom);
    }

    template <typename data_type>
    double specs_algo<data_type>::standard_deviation()
    {
        return std::sqrt(this->variance());
    }

    template <typename data_type>
    ndarray<data_type> specs_algo<data_type>::normalize()
    {
        double mean = this->mean();
        double std = this->standard_deviation();
        ndarray<data_type> answer(rows, collom);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                answer.data[i][j] = (data[i][j] - mean) / std;
            }
        }
        return answer;
    }

    template <typename data_type>
    ndarray<data_type> specs_algo<data_type>::covariance_matrix()
    {
        ndarray<data_type> normalized_data = this->normalize();
        ndarray<data_type> transposed_data = normalized_data.transpose();
        return normalized_data * transposed_data;
    }

    template <typename data_type>
    ndarray<data_type> specs_algo<data_type>::correlation_matrix()
    {
        ndarray<data_type> normalized_data = this->normalize();
        ndarray<data_type> transposed_data = normalized_data.transpose();
        ndarray<data_type> covariance = normalized_data * transposed_data;
        ndarray<data_type> std_deviation(rows, collom);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                std_deviation.data[i][j] = std::sqrt(covariance.data[i][j]);
            }
        }
        return covariance.element_wise_division(std_deviation);
    }

    template <typename data_type>
    ndarray<data_type> specs_algo<data_type>::LU_composition()
    {
        ndarray<data_type> L(rows, collom);
        ndarray<data_type> U(rows, collom);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                if (i > j)
                {
                    L.data[i][j] = data[i][j];
                }
                else
                {
                    U.data[i][j] = data[i][j];
                }
            }
        }
        return L * U;
    }

    template <typename data_type>
    ndarray<data_type> specs_algo<data_type>::cholesky_decomposition()
    {
        ndarray<data_type> L(rows, collom);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collom; j++)
            {
                if (i == j)
                {
                    data[i][j] = std::sqrt(data[i][j]);
                }
                else if (i > j)
                {
                    data[i][j] = 0;
                }
                else
                {
                    data[i][j] = data[i][j] / data[j][j];
                }
            }
        }
        return L;
    }

    template <typename data_type>
    ndarray<data_type> specs_algo<data_type>::QR_decomposition()
    {
        if (rows != collom)
        {
            throw std::runtime_error("dimension error");
        }
        int n = rows;
        ndarray<data_type> Q(n, n);
        ndarray<data_type> R(n, n);
        ndarray<data_type> A = *this;
        // Khởi tạo Q và R về 0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Q[i][j] = 0;
                R[i][j] = 0;
            }
        }
        // Phân rã Gram-Schmidt
        for (int j = 0; j < n; j++)
        {
            std::vector<data_type> v(n);
            for (int i = 0; i < n; i++)
            {
                v[i] = A[i][j];
            }
            for (int i = 0; i < j; i++)
            {
                data_type dot = 0;
                for (int k = 0; k < n; k++)
                {
                    dot += Q[k][i] * A[k][j];
                }
                R[i][j] = dot;
                for (int k = 0; k < n; k++)
                {
                    v[k] -= dot * Q[k][i];
                }
            }
            data_type norm_v = 0;
            for (int k = 0; k < n; k++)
            {
                norm_v += v[k] * v[k];
            }
            norm_v = std::sqrt(norm_v);
            R[j][j] = norm_v;
            if (norm_v > 1e-6)
            {
                for (int k = 0; k < n; k++)
                {
                    Q[k][j] = v[k] / norm_v;
                }
            }
            else
            {
                for (int k = 0; k < n; k++)
                {
                    Q[k][j] = 0;
                }
            }
        }
        return Q * R;
    }

    template <typename data_type>
    ndarray<data_type> specs_algo<data_type>::eigen_value()
    {
        if (rows != collom)
        {
            throw std::runtime_error("dimension error");
        }
        int n = rows;
        ndarray<data_type> A = *this;
        const int max_iter = 1000;
        const data_type tol = static_cast<data_type>(1e-6);

        for (int iter = 0; iter < max_iter; iter++)
        {
            ndarray<data_type> Q(n, n);
            ndarray<data_type> R(n, n);
            // Khởi tạo Q và R về 0
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Q[i][j] = 0;
                    R[i][j] = 0;
                }
            }
            // Phân rã QR theo Gram–Schmidt
            for (int j = 0; j < n; j++)
            {
                std::vector<data_type> v(n);
                for (int i = 0; i < n; i++)
                {
                    v[i] = A[i][j];
                }
                for (int i = 0; i < j; i++)
                {
                    data_type dot = 0;
                    for (int k = 0; k < n; k++)
                    {
                        dot += Q[k][i] * A[k][j];
                    }
                    R(i, j) = dot;
                    for (int k = 0; k < n; k++)
                    {
                        v[k] -= dot * Q[k][i];
                    }
                }
                data_type norm_v = 0;
                for (int k = 0; k < n; k++)
                {
                    norm_v += v[k] * v[k];
                }
                norm_v = std::sqrt(norm_v);
                R(j, j) = norm_v;
                if (norm_v > tol)
                {
                    for (int k = 0; k < n; k++)
                    {
                        Q[k][j] = v[k] / norm_v;
                    }
                }
                else
                {
                    for (int k = 0; k < n; k++)
                    {
                        Q[k][j] = 0;
                    }
                }
            }
            // Tính A_next = R * Q
            ndarray<data_type> A_next(n, n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    A_next[i][j] = 0;
                    for (int k = 0; k < n; k++)
                    {
                        A_next[i][j] += R[i][k] * Q[k][j];
                    }
                }
            }
            // Kiểm tra hội tụ: tổng giá trị tuyệt đối của các phần tử ngoài đường chéo
            data_type off_diag_norm = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        off_diag_norm += std::abs(A_next[i][j]);
                    }
                }
            }
            A = A_next;
            if (off_diag_norm < tol)
            {
                break;
            }
        }
        // Trích xuất trị riêng từ đường chéo
        ndarray<data_type> eig(n, 1);
        for (int i = 0; i < n; i++)
        {
            eig[i][0] = A[i][i];
        }
        return eig;
    }

    template <typename data_type>
    ndarray<data_type> specs_algo<data_type>::eigen_vector()
    {
        if (rows != collom)
        {
            throw std::runtime_error("dimension error");
        }
        int n = rows;
        ndarray<data_type> A = *this;
        // Khởi tạo Q_total là ma trận đơn vị
        ndarray<data_type> Q_total(n, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Q_total[i][j] = (i == j) ? 1 : 0;
            }
        }
        const int max_iter = 1000;
        const data_type tol = static_cast<data_type>(1e-6);

        for (int iter = 0; iter < max_iter; iter++)
        {
            ndarray<data_type> Q(n, n);
            ndarray<data_type> R(n, n);
            // Khởi tạo Q và R về 0
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Q[i][j] = 0;
                    R[i][j] = 0;
                }
            }
            // Phân rã QR theo Gram–Schmidt
            for (int j = 0; j < n; j++)
            {
                std::vector<data_type> v(n);
                for (int i = 0; i < n; i++)
                {
                    v[i] = A[i][j];
                }
                for (int i = 0; i < j; i++)
                {
                    data_type dot = 0;
                    for (int k = 0; k < n; k++)
                    {
                        dot += Q[k][i] * A[k][j];
                    }
                    R[i][j] = dot;
                    for (int k = 0; k < n; k++)
                    {
                        v[k] -= dot * Q[k][i];
                    }
                }
                data_type norm_v = 0;
                for (int k = 0; k < n; k++)
                {
                    norm_v += v[k] * v[k];
                }
                norm_v = std::sqrt(norm_v);
                R(j, j) = norm_v;
                if (norm_v > tol)
                {
                    for (int k = 0; k < n; k++)
                    {
                        Q[k][j] = v[k] / norm_v;
                    }
                }
                else
                {
                    for (int k = 0; k < n; k++)
                    {
                        Q[k][j] = 0;
                    }
                }
            }
            // Cập nhật A = R * Q
            ndarray<data_type> A_next(n, n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    A_next[i][j] = 0;
                    for (int k = 0; k < n; k++)
                    {
                        A_next[i][j] += R[i][k] * Q[k][j];
                    }
                }
            }
            A = A_next;
            // Cập nhật tích lũy Q_total = Q_total * Q
            ndarray<data_type> newQ_total(n, n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    newQ_total[i][j] = 0;
                    for (int k = 0; k < n; k++)
                    {
                        newQ_total[i][j] += Q_total[i][k] * Q[k][j];
                    }
                }
            }
            Q_total = newQ_total;
            // Kiểm tra hội tụ
            data_type off_diag_norm = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        off_diag_norm += std::abs(A[i][j]);
                    }
                }
            }
            if (off_diag_norm < tol)
            {
                break;
            }
        }
        // Các vector riêng là các cột của Q_total
        return Q_total;
    }

    template <typename data_type>
    SVDResult specs_algo<data_type>::SVD_decomposition(const ndarray<data_type> &A)
    {
        if (rows < collom)
        {
            throw std::runtime_error("dimension error: rows must be >= columns");
        }
        int m = rows;
        int n = collom;
        ndarray<data_type> A = *this;
        ndarray<data_type> AT = A.transpose();
        ndarray<data_type> ATA = AT * A; // Kích thước n x n

        // Tính phân rã eigen của ATA (ATA là đối xứng và bán xác định dương)
        ndarray<data_type> eigen_vals = ATA.eigen_value();  // n x 1
        ndarray<data_type> eigen_vecs = ATA.eigen_vector(); // n x n, các vector riêng lưu theo cột

        // Tạo ma trận S đường chéo chứa các singular values (lấy căn bậc hai của trị riêng)
        ndarray<data_type> S_mat(n, n);
        // Khởi tạo S_mat về 0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                S_mat[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            S_mat[i][i] = std::sqrt(eigen_vals(i, 0));
        }

        // Gán V = eigen_vecs (theo giả định các vector riêng được lưu theo cột)
        ndarray<data_type> V = eigen_vecs;

        // Tính U với công thức: U[:,i] = (1/sigma_i) * A * V[:,i]
        ndarray<data_type> U(m, n);
        // Khởi tạo U về 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                U[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            data_type sigma = S_mat[i][i];
            if (sigma > 1e-6)
            {
                for (int r = 0; r < m; r++)
                {
                    data_type sum = 0;
                    for (int k = 0; k < n; k++)
                    {
                        sum += A[r][k] * V[k][i];
                    }
                    U[r][i] = sum / sigma;
                }
            }
            else
            {
                // Nếu singular value quá nhỏ, gán vector U cột i bằng 0
                for (int r = 0; r < m; r++)
                {
                    U[r][i] = 0;
                }
            }
        }

        SVDResult<data_type> result;
        result.U = U;
        result.S = S_mat;
        result.V = V;
        return result;
    }
}