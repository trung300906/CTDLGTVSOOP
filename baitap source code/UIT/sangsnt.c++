#include <iostream>
#include <math.h>
using namespace std;

int prime[10000001]; // N = 10^7

void sang()
{
    // Bước 1 : Coi tất cả các số từ 0 tới N là số nguyên tố
    for (int i = 0; i <= 10000000; i++)
    {
        prime[i] = 1;
    }
    // Bước 2 : Sàng
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 10000000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    int count = 0;
    cin >> n;
    sang();
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            if (prime[i - 2])
            {
                cout << i - 2 << ", " << i << endl;
                count++;
            }
        }
    }
    cout << "Tong: " << count << " cap so sinh doi < " << n;
    return 0;
}