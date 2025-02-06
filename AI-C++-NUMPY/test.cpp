#include <bits/stdc++.h>
#include </run/media/trung/hdddrive/CODE/CTDLGTVSOOP/AI-C++-NUMPY/numpy.h>
using namespace std;

int main()
{
    srand(time(NULL));
    vector<vector<double>> A;
    for (int i = 0; i < 10; i++)
    {
        vector<double> temp;
        for (int j = 0; j < 10; j++)
        {
            temp.push_back(rand() % 10 + 1);
        }
        A.push_back(temp);
    }
    cout << "predict of A: " << endl;
    vector<vector<double>> answer = matrix_sub(A, A);
    for (auto &i : answer)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}