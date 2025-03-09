#ifndef DEFINE_HPP
#define DEFINE_HPP
#include <bits/stdc++.h>

template <typename data_type>
struct position
{
protected:
    data_type x, y;

public:
    position() : x(0), y(0) {};
    position(data_type x_, data_type y_) : x(x_), y(y_) {};
    double distance(const position<data_type> point) const
    {
        return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
    }
    friend std::ostream &operator<<(std::ostream &out, const position<data_type> &nd)
    {
        out << nd.x << " " << nd.y << std::endl;
        return out;
    }
    // Getter để truy cập x, y
    data_type getX() const { return x; }
    data_type getY() const { return y; }
};

template <typename data_type>
struct triangle
{
private:
    position<data_type> A;
    position<data_type> B;
    position<data_type> C;

public:
    triangle()
    {
        std::cout << "Type in point A (x y): ";
        data_type xA, yA, xB, yB, xC, yC;
        std::cin >> xA >> yA;
        A = position<data_type>(xA, yA);

        std::cout << "Type in point B (x y): ";
        std::cin >> xB >> yB;
        B = position<data_type>(xB, yB);

        std::cout << "Type in point C (x y): ";
        std::cin >> xC >> yC;
        C = position<data_type>(xC, yC);
    }
    double chuvi()
    {
        double AB = A.distance(B);
        double AC = A.distance(C);
        double BC = B.distance(C);
        return AB + AC + BC;
    }
    double square()
    {
        double AB = A.distance(B);
        double AC = A.distance(C);
        double BC = B.distance(C);
        double heron = (AB + AC + BC) / 2;
        return sqrt(heron * (heron - AB) * (heron - AC) * (heron - BC));
    }
    position<double> center()
    {
        double x = static_cast<double>(A.getX() + B.getX() + C.getX()) / 3;
        double y = static_cast<double>(A.getY() + B.getY() + C.getY()) / 3;
        return position<double>(x, y);
    }
};
#endif