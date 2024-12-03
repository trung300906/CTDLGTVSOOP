#include <iostream>
using namespace std;

int L, R;

// Hàm kiểm tra số nguyên tố
bool primecheck(int n) {
    if (n == 2 || n == 3)
        return true;
    if (n < 2 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Sàng Eratosthenes trong khoảng [L, R]
void range_eratosthenes(int L, int R, bool is_prime[]) {
    int range = R - L + 1;
    for (int i = 0; i < range; ++i)
        is_prime[i] = true;

    if (L == 1)
        is_prime[0] = false;

    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            is_prime[j - L] = false;
        }
    }
}

// Hàm đảo ngược số
int reverse(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    return rev;
}

int main() {
    cin >> L >> R;
    int count = 0;
    int range = R - L + 1;
    bool is_prime[range];
    
    range_eratosthenes(L, R, is_prime);

    for (int i = 0; i < range; i++) {
        if (is_prime[i]) {
            int num = L + i;
            if (primecheck(reverse(num))) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
