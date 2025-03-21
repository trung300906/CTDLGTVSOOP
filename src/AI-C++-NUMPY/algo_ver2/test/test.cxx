#include <iostream>

class Vector
{
public:
    double x, y;

    Vector(double x = 0, double y = 0) : x(x), y(y) {}

    // Khai báo friend function
    friend Vector operator+(const Vector &a, const Vector &b);
};

// Định nghĩa toán tử + bên ngoài lớp
Vector operator+(const Vector &a, const Vector &b)
{
    return Vector(a.x + b.x, a.y + b.y);
}

int main()
{
    Vector v1(1, 2), v2(3, 4);
    Vector v3 = v1 + v2;

    std::cout << "Result: (" << v3.x << ", " << v3.y << ")\n";
    return 0;
}
