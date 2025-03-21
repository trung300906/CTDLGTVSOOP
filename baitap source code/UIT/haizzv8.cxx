#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Read the number of seeds (k)
        long long k;
        cin >> k;

        // Compute T = 4k - 1
        long long T = 4 * k - 1;

        // Variables to store the best factor pair (A, B)
        long long bestDiff = std::numeric_limits<long long>::max();
        long long bestA = -1, bestB = -1;

        // Loop over possible factors (only odd factors are possible)
        // Note: factor must be at least 3 so that m = (A-1)/2 >= 1.
        for (long long d = 3; d * d <= T; d += 2)
        {
            if (T % d == 0)
            {
                // d is a divisor; let x = d and y = T/d.
                long long x = d;
                long long y = T / d;
                // Make sure x is the smaller factor
                if (x > y)
                    swap(x, y);

                // Both factors have to be at least 3.
                if (x < 3)
                    continue;

                long long diff = y - x;
                if (diff < bestDiff)
                {
                    bestDiff = diff;
                    bestA = x;
                    bestB = y;
                }
            }
        }

        if (bestA == -1)
        {
            // No valid factorization found, so output "-1 -1"
            cout << -1 << " " << -1 << "\n";
        }
        else
        {
            // Compute m and n:
            // bestA = 2m+1  =>  m = (bestA - 1)/2
            // bestB = 2n+1  =>  n = (bestB - 1)/2
            long long m = (bestA - 1) / 2;
            long long n = (bestB - 1) / 2;
            cout << m << " " << n << "\n";
        }
    }
    return 0;
}
