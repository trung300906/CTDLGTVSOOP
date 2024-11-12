#include <bits/stdc++.h>
using namespace std;

int main(){
    pair<int,int> v = make_pair(10,20);
    tuple<int,int,bool> t;
    get<1>(t)= 2;
    get<2>(t) = 3;
    get<3>(t) = false;
}