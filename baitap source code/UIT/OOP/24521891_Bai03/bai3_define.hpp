#ifndef BAI3_DEFINE_HPP
#define BAI3_DEFINE_HPP
#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>

template <typename data_type>
struct phanso
{
private:
    data_type tu, mau;

public:
    phanso(data_type tu_, data_type mau_) : tu(tu_), mau(mau_) {};
    phanso()
    {
        std::cout << "nhap tu so: ";
        std::cin >> tu;
        std::cout << "nhap mau so: ";
        std::cin >> mau;
        if (mau == 0)
            throw std::invalid_argument("mau cannot equal to 0");
    };
    std::pair<data_type, data_type> getter()
    {
        return {this->tu, this->mau};
    }

    friend std::ostream &operator<<(std::ostream &out, const phanso<data_type> &ps)
    {
        out << ps.tu << "/" << ps.mau;
        return out;
    }
    friend std::istream &operator>>(std::istream &input, const phanso<data_type> &ps)
    {
        input >> ps.tu >> ps.mau;
        return input;
    }
    phanso<data_type> &operator=(const phanso<data_type> &ps)
    {
        tu = ps.tu;
        mau = ps.mau;
        return *this;
    }
    phanso<data_type> operator+(const phanso<data_type> &ps) const
    {
        return phanso<data_type>(tu * ps.mau + ps.tu * mau, mau * ps.mau);
    }

    phanso<data_type> operator-(const phanso<data_type> &ps) const
    {
        return phanso<data_type>(tu * ps.mau - ps.tu * mau, mau * ps.mau);
    }

    phanso<data_type> operator*(const phanso<data_type> &ps) const
    {
        return phanso<data_type>(tu * ps.tu, mau * ps.mau);
    }

    phanso<data_type> operator/(const phanso<data_type> &ps) const
    {
        if (ps.tu == 0)
        {
            throw std::domain_error("Không thể chia cho phân số có tử số bằng 0!");
        }
        return phanso<data_type>(tu * ps.mau, mau * ps.tu);
    }
};

template <typename data_type>
phanso<data_type> max(phanso<data_type> ps1, phanso<data_type> ps2)
{
    std::pair<data_type, data_type> ps_1 = ps1.getter();
    std::pair<data_type, data_type> ps_2 = ps2.getter();
    if (static_cast<double>(ps_1.first) / ps_1.second > static_cast<double>(ps_2.first) / ps_2.second)
        return ps1;
    else
        return ps2;
}
#endif