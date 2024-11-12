#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,b,k;
    cin >> n >> b >> k;
    vector<int> ar(n);
    for(auto &i : ar) cin >> i;
    int s = 0;
    for (int i = b; i < b+k ; i++) {
        s+=ar[i % n];
    }
    cout << s;
    return 0;
}
