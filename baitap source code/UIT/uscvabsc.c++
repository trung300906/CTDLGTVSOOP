#include <iostream>
using namespace std;

// Hàm tính GCD sử dụng thuật toán Euclid
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

// Hàm tính LCM dựa trên GCD
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a, b;
    cout << "Nhap hai so nguyen duong a va b: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0)
    {
        cout << "a va b phai la so nguyen duong." << endl;
        return 1;
    }

    cout << "Uoc so chung lon nhat (GCD) cua " << a << " va " << b << " la: " << gcd(a, b) << endl;
    cout << "Boi so chung nho nhat (LCM) cua " << a << " va " << b << " la: " << lcm(a, b) << endl;

    return 0;
}
