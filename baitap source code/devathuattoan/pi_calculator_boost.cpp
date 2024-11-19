#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <omp.h>

using namespace boost::multiprecision;
using namespace std;

// Định nghĩa kiểu số thực với độ chính xác 1 tỷ chữ số
typedef number<cpp_dec_float<1000000>> high_precision_float;

high_precision_float calculate_pi_chudnovsky(long terms)
{
    high_precision_float sum = 0;
    const long C = 640320;
    const long C3_OVER_24 = C * C * C / 24;

    // Sử dụng song song hóa thủ công
    vector<high_precision_float> thread_sums(omp_get_max_threads(), 0);

#pragma omp parallel for
    for (long k = 0; k < terms; ++k)
    {
        int thread_id = omp_get_thread_num();
        high_precision_float numerator = (k % 2 == 0 ? 1 : -1) *
                                         (13591409 + 545140134 * k);
        high_precision_float denominator = 1;
        for (long i = 1; i <= 6 * k; ++i)
            denominator *= i;
        for (long i = 1; i <= 3 * k; ++i)
            denominator /= i;
        for (long i = 1; i <= k; ++i)
            denominator /= (i * i * i);

        numerator *= boost::multiprecision::pow(high_precision_float(C3_OVER_24), k);
        thread_sums[thread_id] += numerator / denominator;
    }

    // Tổng hợp kết quả
    for (const auto &partial_sum : thread_sums)
    {
        sum += partial_sum;
    }

    sum *= 12;
    sum /= boost::multiprecision::sqrt(high_precision_float(C * C * C));
    return 1 / sum;
}

int main()
{
    const long terms = 1000; // Số hạng (tăng để đạt độ chính xác cao hơn)
    cout << "Dang tinh Pi..." << endl;
    high_precision_float pi = calculate_pi_chudnovsky(terms);
    cout << setprecision(50) << pi << endl; // In 50 chữ số đầu tiên
    return 0;
}
