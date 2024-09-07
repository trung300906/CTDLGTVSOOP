#include <bits/stdc++.h>
using namespace std;

struct triple {
    int node1,node2,l;
};
bool duyet(vector<pair<vector<int>, bool>> process){
    for(auto &i: process){
        if(i.second == false) return false;
    }
    return true;
}
bool nope_zero(int a, int b){
    if(a == 0) return false; // loại trừ số 0
    if(b == 0) return true;  // loại trừ số 0
    return a < b;
} 
bool compare(triple node1, triple node2){
    return node1.node1 < node2.node1;
}
int main(){
    int n, m, dau, dich;
    cin >> n >> m >> dau >> dich;
    int wayout = dau, waydich = dich;
    dau -=1, dich-=1;
    int runval =1;
    vector<triple> store;
    while(runval <= m){
        int x,y,z;
        cin >> x >> y >> z;
        store.push_back({x-1,y-1,z});
        runval++;
    }
    sort(store.begin(), store.end(), compare);
    cout << "========================================" << endl;
    for(auto &i : store){
        cout << i.node1 +1 << " " <<i.node2+1 << " " << i.l;
        cout << endl;
    }
    
}