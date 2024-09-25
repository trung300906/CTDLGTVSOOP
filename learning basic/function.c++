#include <bits/stdc++.h>
#define MAX 100
using namespace std;

// truyền giá trị
int sum(int x, int y)
{ //=> tạo bản copy của x và y => ko ảnh hưởng đến biến truyền vào
    cout << &x << " " << &y << endl;
    return x + y; // type function return by value
}
// truyền tham chiếu
int sum1(int &x, int &y)
{ //=> pointer thẳng vào vùng nhớ của 2 biến được truyền vào => thay đổi là thay đổi biến
    cout << &x << " " << &y << endl;
    return x + y; // type function return by value
}
// truyền địa chỉ hàm
int sum2(const int *x, const int *y)
{
    cout << x << " " << y << endl;
    return *x + *y; // type function return by value
}
/// hàm trả về theo kiểu
// return by reference , used for class and struct members
int &add(int x, int y)
{
    int value = x + y;
    return value; // trả về tham chiếu của biến value
} // biến value bị hủy khi ra khỏi hàm => undefined behavior
int& max(int &a, int &b)
{
	return a > b ? a : b; // trả về tham chiếu của biến lớn hơn
}
int& getElement(array<int, MAX> &arr, int idx)
{
	return arr[idx]; // trả về tham chiếu tới phần tử idx
}

//return by address
inline int *get_by_address(const int *x, const int *y){
    int *result = new int;
    *result = *x + *y;
    return result;
}
int main()
{
    int x = 10, y = 15;
    cout << "location address memory of x and y: " << &x << ", " << &y << endl;
    int k = sum(x, y);
    cout << "Ket qua: " << k << endl;
    cout << sum1(x, y) << endl;
    cout << sum2(&x, &y) << endl;
    cout << *get_by_address(&x, &y) << endl;
    return 0;
}