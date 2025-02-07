#include <bits/stdc++.h>
using namespace std;

class Sinhvien
{
private:
    string id, ten, mssv;
    double gpa;
    int secrec = 42;

public:
    Sinhvien();                               // this is an constructor
    Sinhvien(string, string, string, double); // this is constructor with parameters
    void xinchao();
    void diemcuasinhvien();
    void nhap();
    void output()
    {
        cout << "nhap ten: ";
        cout << ten;
        cout << "nhap id: ";
        cout << id;
        cout << "nhap mssv: ";
        cout << mssv;
        cout << "nhap gpa: ";
        cout << gpa;
    }
    ~Sinhvien();
};

Sinhvien::Sinhvien()
{
    cout << " this is constructor without parameters...\n";
}
Sinhvien::~Sinhvien()
{
    cout << "this object was destroy... \n";
}
Sinhvien::Sinhvien(string code, string name, string iden, double dtb)
{
    cout << "this is constructor with paramters... \n";
    id = code = "456";
    ten = name = "binh";
    iden = mssv = "2345";
    gpa = dtb = 9.0;
    cout << id << " " << ten << " " << iden << " " << gpa;
}
void Sinhvien::xinchao()
{
    cout << "hello , this is method xinchao from sinvien \n";
}
void Sinhvien::diemcuasinhvien()
{
    cout << "this is method diemcuasinhvien from sinhvien class\n";
}
void Sinhvien::nhap()
{
    cout << "nhap ten: " << endl;
    cin >> ten;
    cout << "nhap id: " << endl;
    cin >> id;
    cout << "nhap mssv: " << endl;
    cin >> mssv;
    cout << "nhap gpa: " << endl;
    cin >> gpa;
}
int main()
{
    {
        Sinhvien x;
        x.xinchao();
        x.diemcuasinhvien();
        x.nhap();
        x.output();
    }
    Sinhvien z;
    int *ptr = (int *)&z;
    cout << *ptr << endl;
    // cout << x.gpa << endl;
    Sinhvien y("123", "trung", "22334", 10.0);
}