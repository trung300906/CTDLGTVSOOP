#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    vector<int> store;
    int x;
    int so = 0;
    int so_temp = 0;
    int dem = 0;
    s.push_back('t');
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            x = s[i] - '0';
            so = so*10 + x;
        } else {
            if(so != so_temp){
                so_temp = so;
                dem++;
            } 
            so = 0;
            x = 0;
        }
    }
    cout << dem;
}