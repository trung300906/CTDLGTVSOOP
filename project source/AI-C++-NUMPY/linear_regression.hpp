#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include "numpy.hpp"

struct tuple_matrix
{
    numpy::ndarray theta;
    numpy::ndarray cost_history;
    numpy::ndarray theta_history;
};

// prefix
#if 0
    // pre test
    void load_txt(std::string &path_to_file, numpy::ndarray &X, numpy::ndarray &y)
    {
        std::ifstream(file);
        file.open(path_to_file);
        if (file.is_open())
        {
            int rows, collom;
            file >> rows >> collom;
            X = numpy::ndarray(rows, collom);
            y = numpy::ndarray(rows, 1);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < collom; j++)
                {
                    file >> X.data[i][j];
                }
                file >> y.data[i][0];
            }
            file.close();
        }
        else
        {
            throw std::runtime_error("file not found");
        }
    }

    // pre test
    void save_txt(std::string &path_to_file, numpy::ndarray &X, numpy::ndarray &y)
    {
        std::ofstream(file);
        file.open(path_to_file);
        if (file.is_open())
        {
            file << X.rows << " " << X.collom << "\n";
            for (int i = 0; i < X.rows; i++)
            {
                for (int j = 0; j < X.collom; j++)
                {
                    file << X.data[i][j] << " ";
                }
                file << "\n";
            }
            for (int i = 0; i < y.rows; i++)
            {
                file << y.data[i][0] << "\n";
            }
            file.close();
        }
        else
        {
            throw std::runtime_error("file not found");
        }
    }
#endif

numpy::ndarray predict_function(numpy::ndarray &X, numpy::ndarray &theta)
{
    numpy::ndarray y = X * theta;
    return y;
}

auto cost_function(numpy::ndarray &X, numpy::ndarray &y, numpy::ndarray &theta)
{
    numpy::ndarray predicted = X * theta;
    numpy::ndarray sqr_error = (predicted - y).power(2);
    double sum_error = sqr_error.sum_all_elements();
    double m = y.size_matrix();
    return (1 / (2 * m)) * sum_error;
}

numpy::ndarray compute_cost_vector(numpy::ndarray &X, numpy::ndarray &y, numpy::ndarray &theta)
{
    numpy::ndarray error = predict_function(X, theta) - y;
    double m = y.size_matrix();
    return (error.transpose() * error) * (1 / (2 * m));
}

#if 1
tuple_matrix gradient_descent(numpy::ndarray &X, numpy::ndarray &y, numpy::ndarray &theta, const double &learning_rate, const int &iterations)
{
    int m = y.size_matrix();
    numpy::ndarray x_t = X.transpose();
    numpy::ndarray cost_history = numpy::ndarray(iterations, 1);
    numpy::ndarray theta_history = numpy::ndarray(iterations, theta.size_matrix());
    /*
    def gradient_descent(X, y, theta, learning_rate, iterations):
    m = len(y)
    cost_history = np.zeros(iterations)
    theta_history = np.zeros((iterations, np.size(X, 1)))
    for i in range(iterations):
        printProgressBar(i,iterations)
        time.sleep(0.0003)
        predictions = X@theta
        theta = theta - (learning_rate / m) * ((np.transpose(X)) @ (predictions - y))
        cost_history[i] = compute_cost_vector(X, y, theta)
        theta_history[i, :] = np.transpose(theta)

    return theta, cost_history, theta_history
    */
    for (int i = 0; i < iterations; i++)
    {
        /*
        numpy::ndarray error = predict_function(X, theta) - y;
        numpy::ndarray gradient = (x_t * error) * (1 / m);
        */
        numpy::ndarray predictions = predict_function(X, theta);
        theta = theta - (X.transpose() * (predictions - y)) * (learning_rate / m);
        // private field
        cost_history.data[i][0] = compute_cost_vector(X, y, theta);
        theta_history.data[i] = theta;
    }
    return tuple_matrix{theta, cost_history, theta_history};
}
#endif
#endif