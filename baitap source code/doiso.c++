#include<bits/stdc++.h>
using namespace std;

int main(){
    float socandoi;
    cin >> socandoi;
    float sogoc = socandoi;
    int dem = 0;
    float somuctieu = 0;
    while(somuctieu <= sogoc){
        socandoi*=2;
        if(socandoi >= 1){
            cout << 1;
            socandoi -=1;
            dem++;
            somuctieu+=1*pow(2,-dem);
        } else {
            cout << 0;
            dem++;
            somuctieu+=0*pow(2,-dem);
        }
    }
    int k = 0;
}