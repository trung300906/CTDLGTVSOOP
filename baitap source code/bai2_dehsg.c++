// bài 2
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string xoachuoi(string &S1){
    for(int i=S1.length()-1; i>=0;i-- ){
        if(S1[i] == ' '){
            S1.erase(S1.begin() + i);
        }
    }
    return S1;
}
string rand_string(string &S2){
    for(int i=0; i<10;i++){
        S2[i] =  static_cast<char>(rand()%(127-32+1) + 32);
    }
    return S2;
}
int main(){
    srand(time(0));
    string S1, S2(10, ' ');
    getline(cin, S1);
    cout << "xâu S1 là: " << S1 << endl;
    xoachuoi(S1);
    cout << "chuỗi S1 hiện tại là: " << S1 << endl;
    getline(cin , S2);
    cout << endl << "chuỗi S2 là: " << S2 << endl;
    int dem = 0;
    for(int i=0; i < S1.length() ; i++){
        for(int j=0; j < S2.length(); j++){
            if(S1[i] == S2[j]){
                dem++;
                break;
            }
        }
    }
    if(dem == S1.length()){
        cout << "có thể ghép từ chuỗi S2 ra S1 được " ;
    } else cout << "chả được đâu đừng cố ";
}
