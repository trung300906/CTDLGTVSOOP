#include <cmath>
#include <stdexcept>
#include <vector>
#include "specs_algo.hpp"
#include "numpy.hpp"

/// LET ME DIE PLEASE ;;;;;;
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
    // Hàm tính trung bình, phương sai, độ lệch chuẩn, chuẩn hóa,
    // ma trận hiệp phương sai và ma trận tương quan đã có sẵn.
    template <typename data_type>
    double ndarray<data_type>::mean()
    {
        double sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < collom; j++)
            {
                sum += data[i][j];
            }
        }
        return sum / size_matrix();
    }

    template <typename data_type>
    double ndarray<data_type>::variance()
    {
        double m = this->mean();
        double sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < collom; j++)
            {
                sum += (data[i][j] - m) * (data[i][j] - m);
            }
        }
        return sum / size_matrix();
    }

    template <typename data_type>
    double ndarray<data_type>::standard_deviation()
    {
        return std::sqrt(variance());
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::normalize()
    {
        double m = this->mean();
        double std = standard_deviation();
        ndarray<data_type> answer(rows, collom);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < collom; j++)
            {
                answer.data[i][j] = (data[i][j] - m) / std;
            }
        }
        return answer;
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::covariance_matrix()
    {
        ndarray<data_type> normalized = normalize();
        ndarray<data_type> transposed = normalized.transpose(); // Giả sử transpose() đã được định nghĩa.
        ndarray<data_type> answer(collom, collom);
        // Khởi tạo answer về 0
        for (int i = 0; i < collom; i++)
        {
            for (int j = 0; j < collom; j++)
            {
                answer.data[i][j] = 0;
            }
        }
        for (int i = 0; i < collom; i++)
        {
            for (int j = 0; j < collom; j++)
            {
                for (int k = 0; k < rows; k++)
                {
                    answer.data[i][j] += transposed.data[i][k] * normalized.data[k][j];
                }
                answer.data[i][j] /= rows;
            }
        }
        return answer;
    }

    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::correlation_matrix()
    {
        ndarray<data_type> normalized = normalize();
        ndarray<data_type> answer(collom, collom);
        // Khởi tạo answer về 0
        for (int i = 0; i < collom; i++)
        {
            for (int j = 0; j < collom; j++)
            {
                answer.data[i][j] = 0;
            }
        }
        for (int i = 0; i < collom; i++)
        {
            for (int j = 0; j < collom; j++)
            {
                for (int k = 0; k < rows; k++)
                {
                    answer.data[i][j] += normalized.data[k][i] * normalized.data[k][j];
                }
                answer.data[i][j] /= rows;
            }
        }
        return answer;
    }

    //================ LU Decomposition =================
    // Thực hiện phân tích LU theo thuật toán Doolittle và lưu trữ
    // cả L và U trong cùng một ma trận LU:
    // - Phần tam giác dưới (với đường chéo bằng 1) là L
    // - Phần tam giác trên là U
    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::LU_composition()
    {
        if (rows != collom)
        {
            throw std::runtime_error("dimension error");
        }
        int n = rows;
        ndarray<data_type> LU(n, n);
        // Copy dữ liệu ban đầu vào LU
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                LU[i][j] = data[i][j];
            }
        }
        for (int k = 0; k < n; k++)
        {
            // Tính U: hàng k, cột k đến n-1
            for (int j = k; j < n; j++)
            {
                data_type sum = 0;
                for (int p = 0; p < k; p++)
                {
                    sum += LU[k][p] * LU[p][j];
                }
                LU[k][j] = LU[k][j] - sum;
            }
            // Tính L: cột k, hàng k+1 đến n-1
            for (int i = k + 1; i < n; i++)
            {
                data_type sum = 0;
                for (int p = 0; p < k; p++)
                {
                    sum += LU[i][p] * LU[p][k];
                    `
                }
                LU[i][k] = (LU[i][k] - sum) / LU[k][k];
            }
        }
        return LU;
    }

    //================ QR Decomposition =================
    // Phiên bản trả về ma trận Q của phân rã QR sử dụng Gram–Schmidt.
    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::QR_decomposition()
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
            R(j, j) = norm_v;
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
        return Q;
    }

    //================ Eigenvalue & Eigenvector =================
    // Sử dụng thuật toán lặp QR để tính trị riêng của ma trận vuông đối xứng.
    // Phương pháp này cũng cho ta các vector riêng thông qua tích lũy ma trận Q.
    template <typename data_type>
    ndarray<data_type> ndarray<data_type>::eigen_value()
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
    ndarray<data_type> ndarray<data_type>::eigen_vector()
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

    //================ SVD Decomposition =================
    // Vì SVD trả về 3 thành phần (U, S, V), ta định nghĩa cấu trúc kết quả SVDResult

    // Cài đặt SVD dựa trên phân rã của A^T * A (giả sử rows >= collom)
    template <typename data_type>
    SVDResult<data_type> SVD_decomposition(const ndarray<data_type> &A)
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

} // namespace numpy
