#include <bits/stdc++.h>
using namespace std;

void matrixprt(vector<vector<double>> &A)
{
    for (auto &i : A)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
auto matrix_sub(vector<vector<double>> &A, vector<vector<double>> &Theta)
{
    // A@Theta
    if (A[0].size() != Theta.size())
    {
        throw runtime_error("dimension error...");
    }
    else
    {
        vector<vector<double>> answer(A[0].size(), vector<double>(Theta.size(), 0));
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < Theta[0].size(); j++)
            {
                for (int k = 0; k < A[0].size(); k++)
                {
                    answer[i][j] += A[i][k] * Theta[k][j];
                }
            }
        }
        return answer;
    }
}
auto transpose_matrix(vector<vector<double>> &A)
{
    vector<vector<double>> answer(A[0].size(), vector<double>(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            answer[j][i] = A[i][j];
        }
    }
    return answer;
}
auto matrix_addition(vector<vector<double>> &A, vector<vector<double>> &B)
{
    if (A.size() != B.size() && A[0].size() != B[0].size())
    {
        throw runtime_error("dimension error");
    }
    else
    {
        vector<vector<double>> answer(A.size(), vector<double>(A[0].size(), 0));
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                answer[i][j] += A[i][j] + B[i][j];
            }
        }
        return answer;
    }
}
auto matrix_subtraction(vector<vector<double>> &A, vector<vector<double>> &B)
{
    if (A.size() != B.size() && A[0].size() != B[0].size())
    {
        throw runtime_error("dimension error");
    }
    else
    {
        vector<vector<double>> answer(A.size(), vector<double>(A[0].size(), 0));
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                answer[i][j] += A[i][j] - B[i][j];
            }
        }
        return answer;
    }
}
auto inverse_matrix(const vector<vector<double>> &A)
{
    int n = A.size();

    // Kiểm tra ma trận vuông
    for (const auto &row : A)
    {
        if (row.size() != n)
        {
            throw runtime_error("Ma trận phải là ma trận vuông.");
        }
    }

    // Tạo ma trận mở rộng [A | I]
    vector<vector<double>> augmented_matrix(n, vector<double>(2 * n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            augmented_matrix[i][j] = A[i][j];
        }
        augmented_matrix[i][n + i] = 1; // Thêm ma trận đơn vị vào bên phải
    }

    // Thực hiện Gauss-Jordan elimination
    for (int i = 0; i < n; i++)
    {
        // Tìm phần tử chéo chính khác 0
        if (augmented_matrix[i][i] == 0)
        {
            // Tìm dòng khác để đổi
            bool found = false;
            for (int k = i + 1; k < n; k++)
            {
                if (augmented_matrix[k][i] != 0)
                {
                    swap(augmented_matrix[i], augmented_matrix[k]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                throw runtime_error("Ma trận suy biến, không thể tính nghịch đảo.");
            }
        }

        // Chia dòng i cho phần tử chéo chính để đưa về 1
        double diagonal = augmented_matrix[i][i];
        for (int j = 0; j < 2 * n; j++)
        {
            augmented_matrix[i][j] /= diagonal;
        }

        // Loại bỏ các phần tử cùng cột
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = augmented_matrix[k][i];
                for (int j = 0; j < 2 * n; j++)
                {
                    augmented_matrix[k][j] -= factor * augmented_matrix[i][j];
                }
            }
        }
    }

    // Tách ma trận nghịch đảo từ ma trận mở rộng
    vector<vector<double>> inverse(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inverse[i][j] = augmented_matrix[i][n + j];
        }
    }

    return inverse;
}
auto element_wise_multiplication(const vector<vector<double>> &A, const vector<vector<double>> &B)
{
    if (A.size() != B.size() || A[0].size() != B[0].size())
    {
        throw runtime_error("dimension error");
    }
    vector<vector<double>> result(A.size(), vector<double>(A[0].size()));
    for (size_t i = 0; i < A.size(); ++i)
    {
        for (size_t j = 0; j < A[0].size(); ++j)
        {
            result[i][j] = A[i][j] * B[i][j];
        }
    }
    return result;
}
auto element_wise_division(const vector<vector<double>> &A, const vector<vector<double>> &B)
{
    if (A.size() != B.size() || A[0].size() != B[0].size())
    {
        throw runtime_error("dimension error");
    }
    vector<vector<double>> result(A.size(), vector<double>(A[0].size()));
    for (size_t i = 0; i < A.size(); ++i)
    {
        for (size_t j = 0; j < A[0].size(); ++j)
        {
            if (B[i][j] == 0)
                throw runtime_error("division by zero");
            result[i][j] = A[i][j] / B[i][j];
        }
    }
    return result;
}
auto multiplication_matrix(vector<vector<double>> &A, const double &scalor)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            A[i][j] *= scalor;
        }
    }
}
auto division_matrix(vector<vector<double>> &A, const double &scalor)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            A[i][j] /= scalor;
        }
    }
}
double determinant(const vector<vector<double>> &A)
{
    int n = A.size();
    for (const auto &row : A)
        if (row.size() != n)
            throw runtime_error("Ma trận phải là ma trận vuông.");

    if (n == 1)
        return A[0][0];
    if (n == 2)
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];

    double det = 0;
    for (int p = 0; p < n; p++)
    {
        vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));
        for (int i = 1; i < n; i++)
        {
            int sub_j = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == p)
                    continue;
                subMatrix[i - 1][sub_j] = A[i][j];
                sub_j++;
            }
        }
        det += A[0][p] * pow(-1, p) * determinant(subMatrix);
    }
    return det;
}
int matrix_rank(vector<vector<double>> A)
{
    int m = A.size();
    int n = A[0].size();
    int rank = 0;

    for (int row = 0; row < m; row++)
    {
        bool non_zero = false;
        for (int col = 0; col < n; col++)
        {
            if (A[row][col] != 0)
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
double trace(const vector<vector<double>> &A)
{
    if (A.size() != A[0].size())
        throw runtime_error("Ma trận phải là ma trận vuông.");
    double tr = 0;
    for (size_t i = 0; i < A.size(); ++i)
    {
        tr += A[i][i];
    }
    return tr;
}
auto reshape_matrix(const vector<vector<double>> &A, size_t new_rows, size_t new_cols)
{
    size_t total_elements = A.size() * A[0].size();
    if (new_rows * new_cols != total_elements)
        throw runtime_error("Số phần tử không khớp.");

    vector<double> flat;
    for (const auto &row : A)
        flat.insert(flat.end(), row.begin(), row.end());

    vector<vector<double>> result(new_rows, vector<double>(new_cols));
    size_t index = 0;
    for (size_t i = 0; i < new_rows; ++i)
    {
        for (size_t j = 0; j < new_cols; ++j)
        {
            result[i][j] = flat[index++];
        }
    }
    return result;
}
double sum_all_elements(const vector<vector<double>> &A)
{
    double sum = 0;
    for (const auto &row : A)
        for (const auto &elem : row)
            sum += elem;
    return sum;
}
auto element_wise_power(const vector<vector<double>> &A, double exponent)
{
    vector<vector<double>> result(A.size(), vector<double>(A[0].size()));
    for (size_t i = 0; i < A.size(); ++i)
    {
        for (size_t j = 0; j < A[0].size(); ++j)
        {
            result[i][j] = pow(A[i][j], exponent);
        }
    }
    return result;
}
auto kronecker_product(const vector<vector<double>> &A, const vector<vector<double>> &B)
{
    size_t m = A.size();
    size_t n = A[0].size();
    size_t p = B.size();
    size_t q = B[0].size();

    vector<vector<double>> result(m * p, vector<double>(n * q));
    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            for (size_t k = 0; k < p; ++k)
            {
                for (size_t l = 0; l < q; ++l)
                {
                    result[i * p + k][j * q + l] = A[i][j] * B[k][l];
                }
            }
        }
    }
    return result;
}
auto size_matrix(vector<vector<double>> &A)
{
    return A.size() * A[0].size();
}