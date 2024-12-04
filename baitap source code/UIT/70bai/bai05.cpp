#include <iostream>
#include <limits.h>
using namespace std;

int findLargestNegative(int a[], int n) {
    int maxNegative = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0 && a[i] > maxNegative) {
            maxNegative = a[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int a[] = {1, -3, -4, -2, -5};
    int n = sizeof(a) / sizeof(a[0]);
    int index = findLargestNegative(a, n);
    if (index != -1) {
        cout << "The index of the largest negative element is: " << index << endl;
    } else {
        cout << "No negative element found" << endl;
    }
    return 0;
}
