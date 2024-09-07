#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout << "nhập số phần tử của mảng: " ; 
    do{
        cin >> n;
    } while (n>=0);
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int S=0;
    int repeat=0;
    for(int i=0 ; i<n; i++){
        if(repeat != a[i]){
            S += a[i];
        }
        repeat =  a[i];
    }
    cout << "tổng số n liên tiếp là: " << S << endl;
}