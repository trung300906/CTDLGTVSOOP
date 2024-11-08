#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10; // Lấy chữ số cuối cùng và cộng vào tổng
        n /= 10;       // Bỏ chữ số cuối cùng
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDigits(n) << endl;
    return 0;
}
