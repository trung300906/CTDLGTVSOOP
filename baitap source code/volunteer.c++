#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> volun_val;
    int x, n;
    cin >> n; // nhập số tình nguyện viên
    int q_n;
    cin >> q_n; // nhập số câu hỏi
    vector<pair<int,int>> quest_n(q_n);
    for(int i = 0 ; i < n ; i ++){
        x =  rand() % 10000 +  1;
        volun_val.push_back(x);
        cout << volun_val[i] << " ";
    }
    int a, b;
    cout<< endl << "====================" << endl;
    for(int i = 0 ; i  <  q_n; i++){
        a  = rand()% 10000;
        quest_n[i].first = a;
        b = rand()% 10000;
        while(b < a){
            b=rand()% 10000;
        }
        quest_n[i].second = b;
        cout << a << " " << b << endl;
    }
    sort(volun_val.begin(), volun_val.end());
    int dem = 0 ;
    cout << "===============================" << endl;
    for(int i = 0 ; i < q_n; i++){
        for(int j = 0; j <  n; j++){
            if(volun_val[j]>= quest_n[i].first && volun_val[j]<= quest_n[i].second){
                dem++;
            }
        }
        cout << dem << endl;
        dem = 0;
    }
}