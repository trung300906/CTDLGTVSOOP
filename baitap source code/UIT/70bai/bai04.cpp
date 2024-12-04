#include <iostream>
#include <limits.h>
using namespace std;

int findSecondLargest(int a[], int n) {
    if (n < 2) return -1;
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            secondLargest = largest;
            largest = a[i];
        } else if (a[i] > secondLargest && a[i] != largest) {
            secondLargest = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == secondLargest) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[] = {1, 3, 4, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int index = findSecondLargest(a, n);
    if (index != -1) {
        cout << "The index of the second largest element is: " << index << endl; //counter from zero
    } else {
        cout << "No second largest element found" << endl;
    }
    return 0;
}
