#include <bits/stdc++.h>
using namespace std;

int defragnum(int n, int stm[2][10]){
    int so,i;
    while(n>1){
        so=n%10;
        i=0;
        do{
            if(so==stm[0][i]){
                stm[1][i]++;
            }
            i++;
        } while(so!=stm[0][i-1]);
        n/=10;
        
    }
    return stm[2][10];
}
int main(){
    srand(time(NULL));
    int n=10;
    int a[n];
    int stm[2][10]= {{0,1,2,3,4,5,6,7,8,9},{0,0,0,0,0,0,0,0,0,0}};
    for(int i=0;i < n; i++){
        a[i] = rand() % 100 +1;
        cout << a[i] << "\t";
        defragnum(a[i], stm);
    }
    cout << endl;
    for(int i=0; i< 2;i++){
        for(int j=0;j<10;j++){
            cout << stm[i][j] << "\t";
        }
        cout << endl;
    }
    for( int i=0 ; i< 10; i++){
        if(stm[1][i] == 1){
            cout << "các số xuất hiện ít là: " << stm[0][i] << endl;
        }
    }
}