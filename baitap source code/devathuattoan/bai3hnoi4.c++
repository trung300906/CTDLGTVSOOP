#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    for (int i = 0; i < 10; i++) {
        cout << arr[i % n] << " ";
    }
    cout << INT_MAX;
    return 0;
}
