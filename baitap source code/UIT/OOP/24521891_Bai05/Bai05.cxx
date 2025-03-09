#include <bits/stdc++.h>
using namespace std;

struct Sp
{
private:
    double real, img;

public:
    Sp(double riu, double img_) : real(riu), img(img_) {};
    Sp()
    {
        cout << "nhap phan thuc: ";
        cin >> real;
        cout << "nhap phan ao: ";
        cin >> img;
    }
    friend ostream &operator<<(ostream &out, const Sp &pg)
    {
        out << pg.real << "+(" << pg.img << ")i";
        return out;
    }
    friend istream &operator>>(istream &input, Sp &pg)
    {
        input >> pg.real >> pg.img;
        return input;
    }
    Sp operator=(const Sp &pg)
    {
        real = pg.real;
        img = pg.img;
        return *this;
    }
    Sp operator+(const Sp &pg)
    {
        return Sp(this->real + pg.real, this->img + pg.img);
    }
    Sp operator-(const Sp &pg)
    {
        return Sp(this->real - pg.real, this->img - pg.img);
    }
    Sp operator*(const Sp &pg)
    {
        return Sp(real * pg.real - img * pg.img, real * pg.img + img * pg.real);
    }
};

int main()
{
    Sp s1, s2;
    Sp s3 = s1 + s2;
    Sp s4 = s3 * s2 + s1 - s2;
    cout << s3 << endl
         << s4;
}