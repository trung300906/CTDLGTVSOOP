#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int value = 10;
    // int *ptr = &value; //=> error because it's violate about the const
    // instead
    const int *ptr = &value; // const value pointer

    int a = 10;
    const int *ptr_1 = &a; // const value pointer
    //*ptr_1 = 20; // it's unvalid as it's a const pointer pointing to a const value
    a = 20;
    // with a const value pointer, u cannt change or edit variables thorugh pointer to this value, just can be changed
    // throught this variable you need edit as well

    int value_2 = 2;
    int *ptr_2 = &value_2;
    *ptr_2 = 30; // it's valid as it's a pointer pointing to a non-const value

    int value1 = 5;
    const int *ptr3 = &value1; // ptr là con trỏ hằng

    int value2 = 6;
    ptr3 = &value2; // con trỏ hằng có thể trỏ đến địa chỉ khác

    // const to pointer is pointer to memory allocated const, It's can pointer to another memory allocated, but cannot
    // change the value of variable it's pointer to
    //  const pointer
    /* const pointer >< const to pointer, It's cannot change the memory allocated it's point to, but can directly change   the value of variable pointed */
    // for ex:
    int *const ptrr = &value1;
    *ptrr = 70;     // it's valid as it's a pointer to memory allocated const
    //ptrr = &value2; // error
     //when you combine const to ointer with const pointer, you will have a pointer cannot change memory allocated and value of variable it's pointed to
    const int *const ptrr_2 = &value;
    //system("pause");
}