#include <iostream>
using namespace std;

auto checkmang(int n, int a[]){
    int check = 0;
    {// trường hợp 1
        for(int i=0; i<(n/2); i++){
            if(a[i] == a[n-i-1]){
                check = 1;
            }
        }
        if(check == 1) return 1;
        check = 0;
    }
    {// trường hợp 2
        for(int i=0; i<n; i++){
            if(a[i] < a[i+1]){
                check = 1;
            } else {
                check = 0;
                break;
            }
        }
        if(check == 1) return 2;
        check = 0;
        for(int i=0; i<n; i++){
            if(a[i] > a[i+1]){
                check = 1;
            } else {
                check = 0;
                break;
            }
        }
        if(check == 1) return 2;
        check = 0;
    }
    {// trường hợp 3
        if(a[0] ==  a[n-1]) check = 1;
        if(check == 1) return 3;
        check = 0;
    }
    {// trường hợp 4
        for(int i=1; i<n; i++){
            if(a[0] == a[i]){
                check = 1;
                break;
            }
        }
        if(check == 1) return 4;
        check = 0;
    } 
    return 5;
}
// trường hợp mảng tăng liên tục
int xulymangth1(int n, int a[]){
    int after[n],store[n], last[n*2];
    for(int i=0; i<n; i++){
        after[i] = 0;
        store[i] = a[i];
        last[i] = a[i];
    }
    if(n%2 == 0){
        for(int i=0; i< n-1; i++){
            after[i] = a[n-i-2]; // đảo mảng lại
            last[n+i] = after[i]; // ghép mảng
        } 
    }
    return last[n*2];
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int check = checkmang(n, a);
    cout << check;
}