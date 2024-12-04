#include <iostream>
using namespace std;

void deleteDuplicatesExceptFirst(int a[], int& n, int X) {
    bool foundFirst = false;
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == X) {
            if (!foundFirst) {
                foundFirst = true;
                a[newSize++] = a[i];
            }
        } else {
            a[newSize++] = a[i];
        }
    }
    n = newSize;
}

int main() {
    int a[] = {1, 2, 3, 2, 2, 4, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int X = 2;
    deleteDuplicatesExceptFirst(a, n, X);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
