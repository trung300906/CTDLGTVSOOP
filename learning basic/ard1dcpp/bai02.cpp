
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void NhapmangSNT(int a[], int &n);
int SoPhanTuChuaY(int a[], int n, int y);

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

void NhapmangSNT(int a[], int &n)
{
    cin >> n;
    int count = 0;
    sang();
    for (int i = 2; i < 10000000; i++)
    {
        if (prime[i])
        {
            a[count] = i;
            count++;
        }
        if (count == n)
        {
            break;
        }
    }
}
bool tachso(int n, int y)
{
    int du = 0;
    while (n > 0)
    {
        du = n % 10;
        if (du == y)
            return true;
        n /= 10;
    }
    return false;
}
int SoPhanTuChuaY(int a[], int n, int y)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (tachso(a[i], y))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int a[MAX], n, y;
    cin >> y;
    NhapmangSNT(a, n);
    cout << SoPhanTuChuaY(a, n, y) << endl;
    return 0;
}