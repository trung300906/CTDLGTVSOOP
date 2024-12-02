#include <iostream>
using namespace std;

auto absf(double input)
{
    return input < 0 ? -input : input;
}
double sqrt_custom(double i)
{
    double guess = i / 2.0;
    double epsilon = 0.00001;
    while (absf(guess * guess - i) >= epsilon)
    {
        guess = (guess + i / guess) / 2.0;
    }
    return guess;
}

int sum_all_square(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int can = static_cast<int>(sqrt_custom(static_cast<double>(i)));
        if (n % i == 0 && can * can == i)
            sum += i;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << sum_all_square(n) << endl;
}