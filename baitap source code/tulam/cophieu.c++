#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){ return a.first > b.first;}
int main(){
    srand(time(0));
    vector<int> input(10);
    int loinhuannew=0;
    int loinhuanold=0;
    int mua;
    int ban;
    for(int i=0; i<10;i++){
        input[i] = rand()%100+1;
        cout << input[i] << " ";
    }
    cout<< endl << "=================" << endl;
    for(int i = 0 ; i <10; i++){
        for(int j = input.size(); j >=i; j--){
            loinhuannew = input[j] - input[i];
            if(loinhuannew > loinhuanold){
                loinhuanold = loinhuannew;
                mua = i;
                ban = j;
            }
        }
    }
    cout << "mua: " << mua+1 << " với giá: "<< input[mua] << " bán: " << ban+1 << " với giá: " << input[ban] << endl;
    cout << "lợi nhuận: " << loinhuanold;
}