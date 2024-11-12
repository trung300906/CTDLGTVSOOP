#include <bits/stdc++.h>
using namespace std;

struct mydata{
    pair<int, int> node;
    bool check;
};
vector<mydata> w;
vector<int> dich;
vector<int> ans;
int n, m , k;
auto dequy(int bd, int end, int cost){
    if(bd < 0 || bd > n || end < 0 || end > n) return -1;
    if(bd == end){
        ans.push_back(cost);
        return cost;
    }
    for(auto &i : w){
        if(i.node.first == bd && i.check == false){
            i.check = true;
            int result = dequy(i.node.second, end, cost+1);
            if(result != -1) return result;
        }
        if(i.node.second == bd && i.check == false){
            i.check = true;
            int result = dequy(i.node.first, end, cost+1);
            if(result != -1) return result;
        }
    }
    return -1;
}
auto xet(){
    if(ans.empty()) return false;
    for(auto &i : ans){
        if(i > k) return false;
    }
    return true;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1; i<= n-1; i++){
        mydata temp;
        cin >> temp.node.first >> temp.node.second;
        temp.check = false;
        w.push_back(temp);
    }
    for(int i = 0 ; i < m ; i++){
        int x;  cin >> x;
        dich.push_back(x);
    }
    int dem = 0;
    for(int i = 1; i <= n; i++){
        ans.clear();
        for(auto &j : dich){
            for(auto &j : w) j.check = false;
            dequy(i,j, 0);
            if(xet()) dem++;
        }
    }
    cout << dem;
}