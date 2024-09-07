#include <iostream>
using namespace std;
int main(){
    int a, b, c, d;
    // there some interact with variables in C++
    //cout some variables
    cout << a << b << c << d;
    //if an variable not have any input, mean just create and do nothing, compiler will make some random variable for this variable
    //cin into a variable
    cin >> a >>b >> c >> d;
    //some interact math with variables
    a= b;
    b = c;
    a = b+1;
    a =b+c+d;
    a = b++; // input for a then b will plus 1 after
    a = ++b; // b plus 1 then a = b
    a+=1; // same with ++a
    a-=1; // same with --a
    return 0;  //return 0 mean program end normally
}