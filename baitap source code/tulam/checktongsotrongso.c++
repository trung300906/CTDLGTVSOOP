#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, k=0, du;
    cin >> n;
    while(n>=1){
       du =n%10;
       k += du;
       n /=10;
    }
    cout << "tổng số trong số đó là: " << k;
}