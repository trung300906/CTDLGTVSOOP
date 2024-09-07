#include <bits/stdc++.h>
using namespace std;

auto duyet(string s, string tempura, vector<string> store, int run, auto it){
    if(run == s.size()){
        return it;
    }
    for(run; run < s.size(); run++){
        tempura += s[run];
        auto tempu = it;
        tempu = find(store.begin(), store.end(), tempura);
        if(tempu != store.end()){
            duyet(s, tempura, store, run + 1, tempu);
            tempura.clear();
            return it;
        } else continue;
    }
    return it;
}
int main(){
    string s;
    cin >> s;
    vector<string> store;
    string x;
    for(int i = 0; i < 3; i++){
        cin >> x;
        store.push_back(x);
    }
    /* while(cin >> x){
        store.push_back(x);
    } */
    int run;
    vector<char> temp;
    string tempura;
    for(run = 0 ; run < s.size();++run){
        tempura += s[run];
        auto it = find(store.begin(), store.end(), tempura);
        if(it != store.end()){
            int location = duyet(s, tempura, store, run + 1, it) - store.begin();
            cout << location << " ";
            tempura.clear();
        } else {
            continue;
        }
    }
}