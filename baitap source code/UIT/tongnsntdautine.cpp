#include <iostream>
#include <cmath>

using namespace std;

int sum_first_n_primes(int n) {
    // Start with a larger limit to ensure we capture enough primes
    int limit = max(n * 15, 200); // Increased limit for higher reliability

    bool* is_prime = new bool[limit + 1];

    for (int i = 0; i <= limit; ++i) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;
    int count = 0;
    int sum = 0;
    for (int p = 2; p <= limit && count < n; ++p) {
        if (is_prime[p]) {
            sum += p;
            ++count;
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    delete[] is_prime;
    return sum;
}

int main() {
    int n; // Number of primes to sum
    int attempts = 0;
    do {
        if (attempts > 0) {
            cout << "Gia tri vua nhap la " << n << ", khong hop le. Vui long nhap lai." << endl;
        }
        cin >> n;
        attempts++;
    } while (n > 50 || n <= 0);
    
    cout << "Tong " << n << " so nguyen to dau tien la: " << sum_first_n_primes(n) << endl;

    return 0;
}
