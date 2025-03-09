#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.141592653589793;

template <typename T>
struct Position
{
protected:
    T x, y;

public:
    Position() : x(0), y(0) {}
    Position(T x_, T y_) : x(x_), y(y_) {}

    T getX() const { return x; }
    T getY() const { return y; }

    void input()
    {
        cin >> x >> y;
    }
};

template <typename T>
struct Circle
{
private:
    Position<T> center;
    T radius;

public:
    Circle() : radius(0) {}

    void input()
    {
        cout << "Nhập tọa độ tâm (x y): ";
        center.input();
        cout << "Nhập bán kính: ";
        cin >> radius;
    }

    double perimeter() const
    {
        return 2 * PI * radius;
    }

    double area() const
    {
        return PI * radius * radius;
    }

    void display() const
    {
        cout << "Chu vi: " << perimeter() << "\n";
        cout << "Diện tích: " << area() << "\n";
    }
};

int main()
{
    Circle<double> c;
    c.input();
    c.display();
    return 0;
}
