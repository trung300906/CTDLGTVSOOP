#include<bits/stdc++.h>
using namespace std;

struct something{
    int xna, xnb, xnc;
};
void foo(int *&p)
{
	// p là tham chiếu đến con trỏ (sẽ được đề cập ở những bài sau)
	// Hàm này dùng để đánh lừa compiler rằng con trỏ p đã bị thay đổi
	// Mục đích là để chương trình được biên dịch thành công
}
something *somethingptr;
int main(){
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << endl;// print variables of n and m
    cout << &n << " " << &m << endl;//print locate of memory
    //*&n = n
    cout << *&n << " " <<*&m << endl;//print variables of n and m
    int *ptr;
    ptr = &n;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &ptr << endl;
    cout << typeid(&ptr).name() << endl;
    cout << sizeof(somethingptr) << endl;
    cout << sizeof(something) << endl;
    cout << sizeof(ptr) << endl;
    cout << sizeof(n) << endl;
    int *p;
    foo(p);
    cout <<*p << endl;
}