#include <bits/stdc++.h>
using namespace std;

struct struct_type
{
    int value1;
    int value2;
    double vlue3;
};
// double struct in struct
struct diem
{
    int value1;
    int value2;
    int value3;
    struct_type infi;
};
int main()
{
    // normal interactive
    struct_type struct_type;
    struct_type.value1 = 10;
    struct_type.value2 = 20;
    struct_type.vlue3 = 30.5;
    cout << struct_type.value1 << " " << struct_type.value2 << " " << struct_type.vlue3 << endl;
    // using with array
    struct_type array_struct[3];
    for (int i = 0; i < 3; i++)
    {
        array_struct[i].value1 = i * 10;
        array_struct[i].value2 = i * 20;
        array_struct[i].vlue3 = i * 30.5;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << array_struct[i].value1 << " " << array_struct[i].value2 << " " << array_struct[i].vlue3 << endl;
    }
    // using with class vector
    vector<struct_type> vector_struct;
    for (int i = 0; i < 3; i++)
    {
        struct_type temp;
        temp.value1 = i * 10;
        temp.value2 = i * 20;
        temp.vlue3 = i * 30.5;
        vector_struct.push_back(temp);
    }
    for (int i = 0; i < 3; i++)
    {
        cout << vector_struct[i].value1 << " " << vector_struct[i].value2 << " " << vector_struct[i].vlue3 << endl;
    }
    // interact with struct diem
    diem diem;
    diem.value1 = 1;
    diem.value2 = 2;
    diem.infi.value1 = 10;
    diem.infi.value2 = 20;
    diem.infi.value3 = 3.14;
    cout << diem.value1 << diem.value2 << diem.infi.value1 << diem.infi.value2 << diem.infi.value3 << endl;
    // interact with class vector
    vector<diem> vector_diem;
    for (int i = 0; i < 3; i++)
    {
        diem temp;
        temp.value1 = i * 10;
        temp.value2 = i * 20;
        temp.infi.value1 = i * 100;
        temp.infi.value2 = i * 200;
        temp.infi.value3 = i * 3.14;
        vector_diem.push_back(temp);
    }
    for (auto &i : vector_diem)
    {
        cout << i.value1 << i.value2 << i.infi.value1 << i.infi.value2 << i.infi.value3 << endl;
    }
}