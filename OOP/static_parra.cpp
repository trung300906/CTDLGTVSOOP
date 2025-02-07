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
};
int sinhvien::dem = 0;
sinhvien::sinhvien()
{
    // SV00x
    id = "SV" + string(3 - to_string(dem).length(), '0') + to_string(dem + 1);
    dem++;
}
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
int main()
{
    vector<sinhvien> key;
    for (int i = 0; i < 2; i++)
    {
        sinhvien temp;
        temp.input();
        // temp.output();
        key.push_back(temp);
    }
    for (auto &i : key)
    {
        i.output();
        cout << "\n";
    }
}