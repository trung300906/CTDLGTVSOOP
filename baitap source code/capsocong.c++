#include <bits/stdc++.h>
using namespace std;
auto dequy(int u1,int d, int n, int dem){
    if(u1 == n) return dem;
    if(n < 0){
        if(u1 < n) return -1;
    }
    if(n > 0){
        if(u1 > n) return -1;
    }
    return dequy(u1+d, d, n, dem+1);
}
int main(){
    int u1, d, n;
    cin >> u1 >> d >> n;
    cout << dequy(u1,d,n,1);
}