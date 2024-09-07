#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < v.size(); i++){
        v[i] = rand() % 2;
        //cout << v[i] <<" ";
    }
    vector<int> temp;
    temp  = v;
    int count = 0;
    int demtemp = 0;
    auto it = find(v.begin(), v.end(), 0);
    int loc =  it - v.begin();
    int run = 0;
    for(int i = loc; i < n; i++){
        if(v[i] == 0){
            v[i] = 1;
            for(int j = 0 ; j < n ; j++){
                if(v[j] == 1) demtemp+=1;
            }
            count =  max(demtemp, count);
            demtemp = 0;
            if(i == n-1){
                run++;
                i = run;
                v= temp;
            }
            continue;
        }
        if(v[i] == 1){
            v[i] = 0;
            for(int j = 0 ; j < n ; j++){
                if(v[j] == 1) demtemp+=1;
            }
            count =  max(demtemp, count);
            demtemp = 0;
            if(i == n-1){
                run++;
                i = run;
                v= temp;
            }
            continue;
        }
        
    }
    cout << count;
}