#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    int count;
    int chan = 0;
    int le = 0;
    cin >> count;
    for(int i = 1; i<= count; i++){
        int k = rand() % 10;
        if(k % 2 == 0) chan++; else le++;
    }
    cout << "chan: " << chan << endl;
    cout << "le: " << le << endl;
}