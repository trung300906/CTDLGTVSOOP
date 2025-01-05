#include <iostream>
#include <cmath>

int main()
{
    long long n = 2;

    // Sử dụng số thực
    if (sqrt(n) * sqrt(n) == n)
    {
        std::cout << "True (Floating-point comparison)\n";
    }
    else
    {
        std::cout << "False (Floating-point comparison)\n";
    }

    // Sử dụng số nguyên
    long long sqrtN = sqrt(n);
    if (sqrtN * sqrtN == n)
    {
        std::cout << "True (Integer comparison)\n";
    }
    else
    {
        std::cout << "False (Integer comparison)\n";
    }

    return 0;
}
