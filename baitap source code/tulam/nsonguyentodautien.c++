#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int snt){
    for(int i=2 ; i<=sqrt(snt); i++){
        if(snt%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n, dem=0;
    cout << "nhập số các số nguyên tố đầu tiên muốn có ";
    cin >> n;
    cout << "số các số nguyên tố từ 1 đến " << n << " là " << endl;
    int i=2;
    while(dem <n){
        if(isprime(i)){
            cout << i << endl;
            dem++;
        }
        i++;
    }
}
