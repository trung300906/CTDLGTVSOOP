#include <bits/stdc++.h>
using namespace std;

template <typename data_type>
struct phanso
{
private:
    data_type tu;
    data_type mau;

public:
    phanso()
    {
        cout << "nhap tu: ";
        cin >> tu;
        cout << "nhap mau: ";
        cin >> mau;
    }
    bool FP_TN()
    {
        if ((tu < 0 && mau > 0) || (tu > 0 && mau < 0))
            return false;
        if ((tu > 0 && mau > 0) || (tu < 0 && mau < 0))
            return true;
        return true;
    }
    bool check_zero()
    {
        if (tu == 0)
            return false;
        return true;
    }
};

template <typename data_type>
using PS = phanso<data_type>;

int main()
{
    PS<int> my_ps;
    if (my_ps.FP_TN())
    {
        cout << "day la ps duong";
    }
    else
    {
        cout << "day la ps am...";
    }
    if (!my_ps.check_zero())
    {
        cout << "day la ps = 0";
    }
    else
    {
        cout << "day la ps khac 0";
    }
}
