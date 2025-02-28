```cpp
#include<iostream>
#include<vector>
#include<string>
#include"specs_algo.hpp"
#include"numpy.hpp"

double ndarray::mean(){
    double sum = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < collom; j++){
            sum += data[i][j];
        }
    }
    return sum / size_matrix();
}
````
