#include<bits/stdc++.h>
using namespace std;

int main(){
    
    double *ptr;
    cout << ptr << endl;
    ptr = ptr+1;
    cout << ptr << endl;
    ptr = ptr+1; // increase 4 bytes for ptr
    cout << ptr << endl;
    //with array
    int a[4] ={1,2,3,4};
    for(int i = 0 ; i < 4; i++){
        cout <<  &a[i] << endl;
    }
    for(int &i : a){
        cout << &i << endl; // cannot be const right here becauze it's will replace all memory allocated for the first allocation
    }
}   