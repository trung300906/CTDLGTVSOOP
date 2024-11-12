#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>  n;
    vector<int> time(n);
    int s = 0;
    for(int i = 0 ; i < n; i++){
        cin >> time[i];
    }
    for(int i = 0 ; i < n; i++){
        if(i == 0){
            s+=time[i];
        }
        if(i > 0){
            s+= time[i] - time[i-1];
        }
        if(s >= 60){
            cout << "0" << 9 << ":" << "0" << s-60 << endl;
            continue;
        }
        if(s < 10){
            cout<< "0" << 8 << ":" << 0 << s <<endl;
            continue;
        }
        if(s >= 10){
            cout << "0" << 8 << ":" << s << endl;
            continue;
        }
    }
}