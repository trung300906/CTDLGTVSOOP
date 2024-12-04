#include <bits/stdc++.h>
using namespace std;

int main()
{
    // for ex a pointer
    int *ptr;
    int value = 10;
    ptr = &value; // ptr now points to value
    cout << &value << endl;
    cout << ptr << endl;
    cout << **ptr << endl;
    // for ex a pointer to pointer
    int **ptr_ptr;
    ptr_ptr = &ptr;
    cout << "=================" << endl;
    cout << ptr_ptr << endl;
    cout << *ptr_ptr << endl;  // prints value
    cout << **ptr_ptr << endl; // prints
    return 0;
}