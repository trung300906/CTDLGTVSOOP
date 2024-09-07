#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k;
    freopen("HN3.INP", "r", stdin);
    freopen("HN3.OUT", "w", stdout);
    cin >> n >> k;
    int minit = INT_MAX , maxit = 0;
    vector<vector<int>> s(n, vector<int>(2));
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < 2; j++){
            cin  >> s[i][j];
            minit = min(s[i][j], minit);
            maxit = max(s[i][j], maxit);
        }
    }
    int count = 0;
    int dem = 0;
    for(int i = minit; i<= maxit; i++){
        dem = 0;
        for(auto &j : s){
            if(i >= j.front() && i <= j.back()) dem++;
        }
        if(dem == k) count++;
    }
    cout << count;
}