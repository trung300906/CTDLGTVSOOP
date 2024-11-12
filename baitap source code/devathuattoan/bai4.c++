#include<bits/stdc++.h>
using namespace std;

auto locso_phase1(vector<int> tohop){
    
}

int main(){
    vector<int> n = {1,2,3,4,3,2,5};
    vector<int> tohop;
    int dem = 0 , i= 0, j = 3-1;
    while(i<= n.size() - 3){
        for(int k = i; k <= j ; k++){
            tohop.push_back(n[k]);
        }
        for(auto &i: tohop){
            cout << i << " ";
        }
        this_thread::sleep_for(chrono::seconds(1));
        cout << endl;
        if(locso_phase1(tohop) == true || tohop[0] == tohop[tohop.size()- 1]){
            j++;
            if(j == n.size())i++, j = i+2;
            tohop.clear();
            continue;
        } 
        break;
    }
    for(auto &i: tohop){
        cout << i << " ";
    }
    cout <<  "end";
}