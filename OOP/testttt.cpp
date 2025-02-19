#include <iostream>
#include <cmath>

// Khai báo một interface dùng struct (lớp trừu tượng)
struct Shape
{
    // Hàm thuần ảo (pure virtual function)
    virtual double area() const = 0;
    virtual ~Shape() {} // Destructor ảo
};

// Sử dụng tính đóng gói: các thành viên dữ liệu được đặt là private
struct Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    // Override hàm tính diện tích
    double area() const override
    {
        return M_PI * radius * radius;
    }
};

// Lớp Rectangle kế thừa từ Shape
struct Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override
    {
        return width * height;
    }
};

struct rectangle_child : public Rectangle
{
    rectangle_child() : Rectangle(0, 0) {}
    double area_twp()
    {
        return false;
    }
};
int main()
{
    // Mảng các con trỏ tới Shape (đa hình)
    Shape *shapes[] = {new Circle(5), new Rectangle(4, 6)};

    std::cout << "Area of Circle: " << shapes[0]->area() << std::endl;
    std::cout << "Area of Rectangle: " << shapes[1]->area() << std::endl;

    // Giải phóng bộ nhớ
    for (Shape *s : shapes)
        delete s;
    rectangle_child obj_sess;
    std::cout << obj_sess.area_twp();
    return 0;
}
