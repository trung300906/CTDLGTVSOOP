#include <iostream>
using namespace std;

void insertAfterMax(int a[], int& n, int X) {
    int maxIndex = -1;
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            maxIndex = i;
        }
    }

    for (int i = n; i > maxIndex + 1; i--) {
        a[i] = a[i - 1];
    }

    a[maxIndex + 1] = X;
    n++;
}

int main() {
    int a[100] = {1, 2, 5, 3, 4}; // Khai báo mảng với kích thước đủ lớn để chứa phần tử mới
    int n = 5;
    int X = 7;
    insertAfterMax(a, n, X);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
