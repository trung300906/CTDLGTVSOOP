#include <bits/stdc++.h>
using namespace std;
int test;
int n, m;
struct triple{
    pair<int,int> node;
    bool check;
};
vector<triple> graph;
vector<int> ans;
int dem = -1;
int duyet(int nb, int ne, int dem){
    if(nb == ne){
        ans.push_back(dem);
        return dem;
    }
    for(auto &i : graph){
        if(i.check == false){
            if(i.node.first == nb){
                i.check = true;
                int result = duyet(i.node.second, nb , dem+1);
                if(result == -1) return -1;
            }
            if(i.node.second == nb){
                i.check = true;
                int result = duyet(i.node.first, nb, dem+1);
                if(result == -1);
            }
        }
    }
    return -1;
}
auto check(){
    for(auto &i : ans){
        if(i % 2 == 0) return true;
    }
    return false;
}
int main(){
    cin >> test;
    for(int i = 0 ; i < test; i++){
        cin >> n >> m;
        graph = vector<triple>(m);
        for(auto &j : graph){
            cin >> j.node.first;
            cin >> j.node.second;
            j.check = false;
        }
        for(int nb = 1 ; nb <= n; nb++ ){
            for(int ne = n; ne > nb ; ne--) duyet(nb, ne,0);
        }
        if(check()) cout << "YES"; else cout << "NO";
    }

}