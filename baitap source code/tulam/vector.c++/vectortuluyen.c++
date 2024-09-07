#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b){ return a>b;} // hàm có chức năng đảo số
int main(){
   vector<int> a;
   for(int i=0; i<5; i++) a.push_back(i);
   for(int &i:a) cout << i << endl;
   int n; cin >> n;
   a.erase(a.begin() + n); // lệnh xóa 1 phần tử tại vị trí n cú pháp: erase(vector.begin + n);
   for(int &i:a) cout << i << endl;
   // lệnh tìm 1 phần tử:  cú pháp:  find(vector.begin(), vector.end(), numneed);
   int num = 0;
   auto it = find(a.begin(), a.end(), num);
   if(it!=a.end()){
    cout << "số " << num << " cần tìm tại vị trí: " << a.size() - (a.end() - it) +  1 << endl;
   } else {
    cout << "không tìm thấy" << endl ;
   }
   sort(a.begin(), a.begin() +  3); // sắp xếp đến vị trí thứ 3 của vector theo chiều tăng dần
   sort(a.begin(), a.end()); // sắp xếp sạch cả vector theo chiều tăng dần
   sort(a.begin(), a.end(), comp); // sắp xếp đảo cả 1 vector
   sort(a.begin(), a.begin() +  3, comp); // sắp xếp đảo tới vị trí thứ n của 1 vector
   sort(a.begin(), a.end()); // sắp xếp sạch cả vector
   for(int &i:a) cout << i << endl;
}
