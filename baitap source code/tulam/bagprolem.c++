#include<bits/stdc++.h>
using namespace std;

#if 1
bool comp(pair<int, int> a, pair<int, int> b){ 
    return a.second / (double)a.first > b.second / (double)b.first;
}

int main(){
    vector<pair<int, int>> items = {{13,20}, {100,19}, {102, 180}, {235,100}, {13,12}};
    sort(items.begin(), items.end(), comp);
    
    int maxkg = 100,Skg = 0, Sgt = 0;
    for(const auto &i:items){
       cout<< "<" << i.first << "," << i.second << ">" << " ";
    }
    cout << endl;
    for(auto &item : items){
        int count = 0;
        while(item.first <= maxkg - Skg && item.second > 0){
            Skg += item.first;
            Sgt += item.second;
            count++;
        }
        if(count > 0){
            cout << "Đã lấy món đồ có khối lượng và giá trị là: <" << item.first << "," << item.second << "> với số lần: " << count << endl;
        }
        if(Skg >= maxkg) break;
    }
    
    cout << "số kg lấy được và giá trị tổng là: " << Skg << " " << Sgt << endl;
}


#endif
#if 0
bool comp(pair<int, int> a, pair<int, int> b){ return a.first > b.first;}
void locso(vector<pair<int, int>> &items, int maxkg){
    for(int i = items.size() - 1; i >= 0 ; i--){
        if(items[i].first > maxkg || items[i].second == 0 || items[i].first == 0){
            items.erase(items.begin() + i);
        }
    }
}
int main(){
    vector<pair<int, int>> items = {{10,45}, {100,19}, {102, 180}, {5,100}, {12,12}};
    sort(items.begin(), items.end(), comp);
    cout << endl;
    int maxkg = 100,Skg = 0, Sgt = 0;
    locso(items, maxkg);
    cout << "=========================" << endl;
    cout << "số kg và giá trị sau xếp và lọc: ";
    for(const auto &i:items){
       cout<< "<" << i.first << "," << i.second << ">" << " ";
    }
    cout << endl;
    vector<float> tile(items.size());
    for(int i = 0; i < items.size(); i++){
        tile[i] = items[i].second / items[i].first;
    }
    cout << "=========================" << endl;
    auto max_iterator = max_element(tile.begin(), tile.end());
    int positon =  max_iterator -  tile.begin(); //trả chỉ số khi trừ hai iterator
    int dem = 0;
    while(Skg < maxkg){
        Skg += items[positon].first; 
        Sgt += items[positon].second;
        if(Skg > maxkg){
            Skg -= items[positon].first;  
            Sgt -= items[positon].second; 
            tile.erase(tile.begin() + positon);
            items.erase(items.begin() + positon);
            max_iterator = max_element(tile.begin(), tile.end());
            positon = max_iterator - tile.begin();
            if(dem > 0) cout << dem << endl;
            dem = 0;
            if(positon == 0){
                break;
            }
            continue;
        } else if(Skg == maxkg){
            dem++;
            cout << dem << endl;
            break;
        }
        if(dem == 0){
            cout << "lấy vật phẩm có số kg và giá trị lần lượt là: <" << items[positon].first << ","<< items[positon].second << "> với số lần: ";
            dem++;
        } else if(dem != 0){
            dem++;
        }
        if(items.size() == 0){
            break;
        }
    }
    cout << "số kg lấy được và giá trị tổng là: " << Skg << " " << Sgt << endl;
}
#endif
#if 0
int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    for (int i=0; i<=W; i++) {
        for (int j=0; j<n; j++) {
            if (wt[j] <= i) {
                dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);
            }
        }
    }

    return dp[W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();

    cout << knapSack(W, wt, val, n);

    return 0;
}
#endif