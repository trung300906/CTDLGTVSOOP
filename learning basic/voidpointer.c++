#include <bits/stdc++.h>
using namespace std;

int main(){
    /* a pointer always include two information:
    +about memory it point to 
    +about value of variable which pointer to this variable */
    int x = 10;
    void *ptr = &x;
    cout << ptr << endl;
    //cout << *ptr << endl; // error compile
    // *ptr = 20; // error compile
    int *p = (int *)ptr; // type casting
    cout << *p << endl; // output: 20

}