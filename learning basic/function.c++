#include<bits/stdc++.h>
using namespace std;

// truyền giá trị
int sum(int x, int y){ //=> tạo bản copy của x và y => ko ảnh hưởng đến biến truyền vào
    cout << &x << " " << &y << endl;
    return x+y; // type function return by value
}
// truyền tham chiếu
int sum1(int &x, int &y){ //=> pointer thẳng vào vùng nhớ của 2 biến được truyền vào => thay đổi là thay đổi biến
    cout << &x << " " << &y << endl;
    return x+y; // type function return by value
}
// truyền địa chỉ hàm
int sum2(const int *x, const int *y){
    cout << x << " " << y << endl;
    return *x+*y; // type function return by value
}
int main(){
    int x = 10, y=15;
    cout << "location address memory of x and y: " << &x << ", " << &y << endl;
    int k =  sum(x,y);
    cout << "Ket qua: " << k << endl;
    cout << sum1(x,y) << endl;
    cout << sum2(&x,&y) << endl;
    return 0;
 
}