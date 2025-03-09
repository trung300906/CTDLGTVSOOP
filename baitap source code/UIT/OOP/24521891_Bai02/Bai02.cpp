#include <bits/stdc++.h>
using namespace std;

template <typename data_type>
struct toado
{
private:
    data_type x, y;

public:
    toado()
    {
        cout << "nhap toa do x va y lan luot: ";
        cin >> x >> y;
    }
    toado(data_type x_, data_type y_) : x(x_), y(y_) {};
    double distance(toado<data_type> point)
    {
        return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
    }
    friend ostream &operator<<(ostream &out, toado<data_type> point)
    {
        out << point.x << " " << point.y;
        return out;
    }
};
int main()
{
    toado<double> point(2, 1);
    cout << point << endl;
    toado<double> point2;
    cout << "distance: " << point.distance(point2);
}