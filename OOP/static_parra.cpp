#include <bits/stdc++.h>
using namespace std;

class sinhvien
{
private:
    string id, ten, ngaysnh, mssv;
    double gpa;
    static int dem;

public:
    sinhvien();
    void input();
    void output();
    static bool cmp(sinhvien &, sinhvien &);
    friend istream &operator>>(istream &in, sinhvien &a)
    {
        cout << "nhap ten: ";
        getline(in, a.ten);
        cout << "'nhap ngay sinh: ";
        in >> a.ngaysnh;
        cout << "nhap mssv: ";
        in >> a.mssv;
        cout << "nhap gpa: ";
        in >> a.gpa;
        in.ignore();
        return in;
    }
    friend ostream &operator<<(ostream &out, sinhvien &a)
    {
        out << "id: " << a.id << " " << "ho ten: " << a.ten << " " << "ngaysinh: " << a.ngaysnh << " " << "mssv: " << a.mssv << " " << "gpa: " << a.gpa;
        return out;
    }
};
int sinhvien::dem = 1;
sinhvien::sinhvien()
{
    // SV00x
    id = "SV" + string(3 - to_string(dem).length(), '0') + to_string(dem);
    dem++;
}
bool sinhvien::cmp(sinhvien &a, sinhvien &b)
{
    return a.gpa > b.gpa;
}
/*
void sinhvien::input()
{
    cout << "nhap ten: ";
    getline(cin, ten);
    cout << "'nhap ngay sinh: ";
    cin >> ngaysnh;
    cout << "nhap mssv: ";
    cin >> mssv;
    cout << "nhap gpa: ";
    cin >> gpa;
    cin.ignore();
}
void sinhvien::output()
{
    cout << "id: " << id << " " << "ho ten: " << ten << " " << "ngaysinh: " << ngaysnh << " " << "mssv: " << mssv << " " << "gpa: " << gpa;
}
*/
int main()
{
    vector<sinhvien> key;
    for (int i = 0; i < 2; i++)
    {
        sinhvien temp;
        cin >> temp;
        key.push_back(temp);
    }
    sort(key.begin(), key.end(), sinhvien::cmp);
    for (auto &i : key)
    {
        cout << i;
    }
}