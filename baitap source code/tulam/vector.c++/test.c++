#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    cout << a.size();
    auto max_iterator = max_element(a.begin(), a.end());
    int positon =  max_iterator -  a.begin();
    cout << positon;
}