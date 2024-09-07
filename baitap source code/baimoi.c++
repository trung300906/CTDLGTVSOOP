#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    for(auto &i : w) cin >> i;
    sort(w.begin(), w.end(), [](int a, int b){
        return a>b;
    });
    for(int i = 0 ; i < n; i++){
        cout << w[i] << " ";
    }
    cout << endl;
    double k = 0;
    double maxx = 0;
    vector<tuple<int,int,double>> temp;
    for(int i = 0 ; i < n ; i++){
        for(int j = n-1; j > i; j--){
            k = (k, double(w[j])/w[i]);
            maxx =  max(maxx, double(w[j])/w[i]);
            temp.push_back(make_tuple(w[j],w[i],k));
        }
    }
    sort(temp.begin(), temp.end(),  [](const auto &a, const auto &b){
        return get<2>(a) > get<2>(b);
    });
    for(int i = 0; i < n; i++){
        if(get<2>(temp[i]) < maxx){
            cout<< endl << get<0>(temp[i-1]) << " " << get<1>(temp[i-1]); 
            break;
        } 
    }
}