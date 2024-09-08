#include<bits/stdc++.h>
using namespace std;

int main(){
    int a= 1, b =5;
/*     auto check = [](auto x, auto y){
        return x>y?false: true;
    }; */
    auto check = [](int x, int y)-> bool{
        return x>y?false: true;
    };
    bool result = check(a, b);
    cout << result << endl; // Outputs: 1
    return 0;
 
}