#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int temp, dem = 0;
    for(int i = 0 ; i < s.size(); i++){
        temp = s[i] - '0';
        if(temp != 1 && temp != 0) dem++;
    }
    cout << dem;
}