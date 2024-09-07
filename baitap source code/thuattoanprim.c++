#include <bits/stdc++.h>
using namespace std;
bool duyet(vector<pair<vector<int>, bool>> v){
    for(int i=0; i<v.size(); i++) if(v[i].second ==  false) return false;
    return true;
}
bool nope_zero(int a, int b){
    if(a == 0) return false; // loại trừ số 0
    if(b == 0) return true;  // loại trừ số 0
    return a < b;
} 
// dijkstra
int main(){
    srand(time(NULL));
    vector< pair< vector<int>, bool > >v = {
/* positon  0 1 2 3 */
/* way 0*/{{0,1,3,4},false},
/* way 1*/{{1,0,2,0},false},
/* way 2*/{{3,2,0,5},false},
/* way 3*/{{4,0,5,0},false}
    };
    vector<vector<int>> test(2);
    vector<vector<int>> test_t(2);
    for(int i=0 ; i < v.size(); i++){
        test[0].push_back(i);
        test[1].push_back(INT_MAX); // giả sử giá trị các đỉnh là vô cực
    }
    test_t = test; // copy 2 vector
    int way = 2; 
    int way_out = way;//tương đương duyệt way 3, vì vector đếm từ 0
    test[1][way] = 0;
    auto min = min_element(test[1].begin(), test[1].end(), nope_zero);
    int positon;
    while(duyet(v) == false){
        for(int i = 0 ; i < v[way].first.size(); i++){
            if(v[i].second == false && v[way].first[i] != 0){
                if((test[1][way] + v[way].first[i]) < test[1][i]){
                    test[1][i] =  test[1][way] + v[way].first[i];
                }
            }
        }
        v[way].second =  true;
        test_t = test; // khôi phục lại vector test_t để xét duyệt tiếp mà không làm ảnh hưởng đến vector test gốc
        min = min_element(test[1].begin(), test[1].end(), nope_zero);
        positon =  min - test[1].begin();
        way = test[0][positon];
        while(v[way].second ==  true){
            test_t[1][way] = 0;
            min = min_element(test_t[1].begin(), test_t[1].end(), nope_zero);
            if(*min == 0) break;
            positon =  min - test_t[1].begin();
            way = test_t[0][positon];
        }
    }
    // output
    int dem = 0;
    cout << "từ đỉnh " << way_out + 1 << " tới các đỉnh ";
    for(int i=0 ; i < test.size(); i++){
        for(int j = 0 ; j < test[i].size(); j++){
            if(i==0) if(test[i][j] != way_out) cout << " " << test[i][j] + 1 << " ";
            if(i==1) if(test[i][j] != test[1][way_out]) cout << " " << test[i][j] << " ";
        }
        if(dem == 0) {cout << endl << "có giá trị lần lượt là: "; dem++;}
    }
}
#if 0 // kruskal
        if(v[positon].second == false) cost += v[way].first[positon];
        v[way].second  =  true;
        v[way].first[positon] =  0;
        v[positon].first[way] = 0;
        way =  positon;
        min = min_element(v[way].first.begin(), v[way].first.end(),nope_zero); // min loại trừ số 0, tức là không xét duyệt số 0 là min
        positon =  min - v[way].first.begin();
        if(v[positon].second ==  true){
            v[way].first[positon] = 0;
            v[positon].first[way] = 0;
            for(int i=0; i< v[way].first.size(); i++){
                if(v[way].first[i] > 0){
                    test[0].push_back(i); // lưu trữ hàng được xét duyệt vào
                    test[1].push_back(*min_element(v[i].first.begin(), v[i].first.end(),nope_zero)); // lưu trữ các giá trị min tương ứng của từng hàng
                }
            }
            auto min_temp = min_element(test[1].begin(), test[1].end());
            int positon_temp = min_temp - test[1].begin();
            positon = test[0][positon_temp];
        }
#endif

#if 0 // prim
// hàm cần dùng: 
bool duyet(vector<pair<vector<int>, bool>> v){
    for(int i=0; i<v.size(); i++) if(v[i].second ==  false) return false;
    return true;
}
bool nope_zero(int a, int b){
    if(a == 0) return false; // loại trừ số 0
    if(b == 0) return true;  // loại trừ số 0
    return a < b;
} 
// code trong main
    vector< pair< vector<int>, bool > >v = {
    /* positon  1 2 3 4 5*/
    /* way 1*/{{0,1,3,4,0},false},
    /* way 2*/{{1,0,2,0,0},false},
    /* way 3*/{{3,2,0,5,0},false},
    /* way 4*/{{4,0,5,0,0},false},
    /* way 5*/{{0,0,0,0,0},false},
        };
    vector<vector<int>> test(2);
    int dem = 0;
    for(int i=0; i < v.size(); i++){
        for(int j = 0 ; j < v[i].first.size(); j++){
            if(v[i].first[j] != 0){
                dem = 0;
                break;
            } else dem++;
        }
        if(dem == v[i].first.size()) v[i].second =  true;
    } // dùng để loại trừ các cây khung đứng 1 mình tức không có liên kết với bất kỳ khung nào
    int cost = 0;
    int way = rand() %(v.size() - 1) + 0;
    cout<<  way +1 << endl;
    auto min = min_element(v[way].first.begin(), v[way].first.end(), nope_zero);
    int positon = min - v[way].first.begin();
    if(v[positon].second == false) cost+= v[positon].first[way];
    v[way].second= true;
    v[way].first[positon] = 0;
    v[positon].second = true;
    v[positon].first[way] = 0;
    while(duyet(v) == false){
        for(int i=0; i<v.size();i++){
            if(v[i].second == true){
                test[0].push_back(i);
                test[1].push_back(*min_element(v[i].first.begin(), v[i].first.end(), nope_zero));
                // lưu ý là nếu cả cái vector con đó đều có gt là 0 => nó vẫn sẽ nhận giá trị nhỏ nhất là 0 tại vị trí 0(tức 1)
            }
        }
        auto min_temp = min_element(test[1].begin(), test[1].end(), nope_zero);
        int min_positon_temp = min_temp - test[1].begin();
        way = test[0][min_positon_temp];
        min = min_element(v[way].first.begin(), v[way].first.end(), nope_zero);
        positon = min - v[way].first.begin();
        if(v[positon].second == false) cost+= v[positon].first[way];
        v[way].first[positon] =0;
        v[way].second = true;
        v[positon].first[way] =0;
        v[positon].second = true;
        test[0].clear();
        test[1].clear();
    }
    cout << cost;
#endif