#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> cake(n);
    for(auto &i : cake){
        cin  >> i;
    }
    int time = 0;
    int dem = 0;
    for(int i = 0 ; i < n; i++){
        if(i == 0){
            time+= cake[i];
            dem++;
            continue;
        }
        time++;
        if(time+cake[i] < t){
            time += cake[i];
            dem++;
        }
    }
    cout << dem;
}
