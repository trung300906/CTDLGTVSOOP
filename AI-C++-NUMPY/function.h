#include <bits/stdc++.h>
#include </run/media/trung/hdddrive/CODE/CTDLGTVSOOP/AI-C++-NUMPY/numpy.h>
using namespace std;

auto computeCost(vector<vector<double>> &X, vector<vector<double>> &Theta, vector<vector<double>> &y)
{
    vector<vector<double>> predict = matrix_sub(X, Theta);
    vector<vector<double>> sqr_error = element_wise_power(matrix_subtraction(predict, y), 2);
    vector<vector<double>> sum_error = sum_all_elements(sqr_error);
    auto m = size_matrix(y);
    vector<vector<double>> J = division_matrix(sum_error, (1 / (2 * m)));
}
