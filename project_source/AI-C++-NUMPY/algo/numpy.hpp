#ifndef NUMPY_HPP
#define NUMPY_HPP
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>
namespace numpy
{
    template <typename data_type>
    class ndarray
    {
    protected:
        std::vector<std::vector<data_type>> data;
        size_t rows, collom;

    public:
        ndarray(const data_type &r, const data_type &c) : collom(c), rows(r), data(r, std::vector<data_type>(c, 0)) {};
        ndarray(const std::vector<std::vector<data_type>> &d) : data(d), rows(d.size()), collom(d[0].size()) {};
        // use getter and setter for access data in private field
        ndarray<data_type> getter() const;
        void setter(const ndarray<data_type> &nd);

        // for operator overloading
        friend std::ostream &operator<<(std::ostream &os, const ndarray<data_type> &nd);
        friend std::istream &operator>>(std::istream &is, ndarray<data_type> &nd);
        std::vector<data_type> &operator[](const size_t &index);
        std::vector<data_Type> &operator[](const size_t &index) const;
        ndarray<data_type> &operator=(const ndarray<data_type> &nd);
        ndarray<data_type> operator+(const ndarray<data_type> &nd);
        ndarray<data_type> operator-(const ndarray<data_type> &nd);
        ndarray<data_type> operator*(const data_type &scalor);
        ndarray<data_type> operator/(const data_type &scalor);
        ndarray<data_type> operator*(const ndarray &nd);

        // hearder function
        ndarray<data_type> transpose();
        ndarray<data_type> power(const data_type &exponent);
        ndarray<data_type> element_wise_multiplication(const ndarray<data_type> &nd);
        ndarray<data_type> element_wise_division(const ndarray<data_type> &nd);
        data_type sum_all_elements() const;
        data_type trace();
        ndarray<data_type> reshape_matrix(const size_t &new_rows, const size_t &new_collom);
        int rank();
        ndarray<data_type> inverse_matrix();
        data_type size_matrix() const;
        // 0 for get rows and 1 for get collom
        data_type size_matrix(const bool &dimension_choice) const;
        data_type deter() const;
        ndarray<data_type> kronecker_product(const ndarray<data_type> &nd);
    };
}

#endif