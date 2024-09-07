#include <iostream>
using namespace std;
int main() {
    srand(time(NULL));
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        a[i] = rand() % 100 + (-10);
        cout << a[i] << "\t ";
    }
    int L[n], max = 0;
    for (int i = 0; i < n; i++) {
        L[i] = 1; // nếu chưa xét đến độ dài, mỗi phần tử đều có độ lớn chưa xét tại nó là bằng 1
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && L[j] + 1 > L[i])
                L[i] = L[j] + 1;
        if (L[i] > max) max = L[i];
    }
    int b[max], k = max;
    for (int i = n - 1; i >= 0; i--)
        if (L[i] == k) {
            b[--k] = a[i];
            if (k == 0) break;
        }
    for (int i = 0; i < max; i++) cout << b[i] << " ";
    cout << endl;
    return 0;
}
