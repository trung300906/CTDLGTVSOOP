this file will include all header file and overload operator function 
will include more header type of function application, and this file will be include into file 


structure:
and define set block for protected function:
#ifndef NUMPY_HPP
#define NUMPY_HPP
lib included:
#include <vector>
#include <iostream>
#include <math.h>
#include <numeric>

we will define an namespace named numpy here for apply an space of my class
and class will be used is ndarray

//template using:
template<typename data_type>
//operator code using:
operator<<
operator>>
operator[]
operator+
operator-
operator* (for matrix and scalor)
operator/
operator=

and some function will be applied:
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

code:
[Engelbart](https://history-computer.com/ModernComputer/Basis/images/Engelbart.jpg)