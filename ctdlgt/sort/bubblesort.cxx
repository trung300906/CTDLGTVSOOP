    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int nums;
        cin >> nums;
        vector<int> data(nums, 0);
        for(auto &i: data){
            cin >> i;
        }
        for(int i = 1 ; i<= nums; i++){
            for(int j = 0 ; j < nums-1 ; j++){
                if(data[j] > data[j+1]){
                    swap(data[j], data[j+1]);
                    for(auto &k: data){
                        cout << k << " ";
                    }
                    cout << endl;
                }
            }
        }
    }