#include <iostream>
using namespace std;

// Function to calculate the nth Fibonacci number
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    int a = 1, b = 1, c = 0;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int x;
    cin >> x;

    // Check if x is in the valid range
    if (x < 1 || x > 30)
    {
        cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
    }
    else
    {
        // Calculate the xth Fibonacci number
        int fib = fibonacci(x);
        cout << fib;
    }

    return 0;
}
