#include <bits/stdc++.h>
using namespace std;
// update theem cacs saau con
int main(){
    int n=3;
    string s;
    int dem = 0 , max = 0, dem_max = 0;
    for(int i = 0 ; i < n ; i++){
        getline(cin, s);
        for(int i =0 ; i < s.length(); i++){
            if(s[i] != 'A' && s[i] != 'W' && s[i] != 'R'){
                dem++;
            } else if(s[i] == 'A' || s[i] == 'W' || s[i] == 'R'){
                if(dem > max){
                    max = dem ;
                    dem = 0 ;
                    dem_max = 1;
                } else if(dem == max){
                    dem_max++;
                    dem = 0;
                }
            }
        }
        dem = 0;
    }
    cout << max -1 << "\t" << dem_max + 1;
}