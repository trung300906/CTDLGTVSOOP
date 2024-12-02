#include <iostream>
int input()
{
    int n;
    std::cin >> n;
    return n;
}

void input(int &b)
{
    std::cin >> b;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

float TongUocChung(int a, int b)
{
    float sum = 0;
    int gcdk = gcd(a, b);
    for (int i = 1; i <= gcdk; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int a, b;
    a = input();
    input(b);
    std::cout << TongUocChung(a, b) << std::endl;
    return 0;
}
