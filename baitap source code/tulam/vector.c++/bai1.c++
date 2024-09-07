#include <bits/stdc++.h>
using namespace std;

/* Tìm giá trị lớn nhất và nhỏ nhất: Viết chương trình để tìm giá trị lớn nhất và nhỏ nhất trong vector.

Đảo ngược vector: Viết chương trình để đảo ngược thứ tự các phần tử trong vector.

Tính tổng các phần tử: Viết chương trình để tính tổng của tất cả các phần tử trong vector.

Kiểm tra sự tồn tại của một phần tử: Viết chương trình để kiểm tra xem một số nguyên cụ thể có tồn tại trong vector hay không.

Xóa tất cả các phần tử có giá trị cụ thể: Viết chương trình để xóa tất cả các phần tử có giá trị cụ thể khỏi vector.

Nhân mỗi phần tử với một hằng số: Viết chương trình để nhân mỗi phần tử trong vector với một hằng số và in vector kết quả.

Tính giá trị trung bình: Viết chương trình để tính giá trị trung bình của các phần tử trong vector.

Tìm phần tử xuất hiện nhiều nhất: Viết chương trình để tìm phần tử xuất hiện nhiều nhất trong vector. */
int main(){
 srand(time(0));
 vector<int> a;
 for(int i=0; i< 10; i++){a.push_back(rand() % 2 +1); cout << a[i] << " ";}
 #if 1
    // bài 1 dùng max_element and min_element
    /* min_element and max_element trả về một iterator (tương tự như một con trỏ) trỏ đến phần tử nhỏ nhất trong vector.
    Để truy cập giá trị mà iterator này đang trỏ đến, bạn có thể sử dụng toán tử dereference  */
    auto max =  max_element(a.begin(), a.end());
    auto min = min_element(a.begin(), a.end());
    cout << "max của mảng a là: " << *max << endl;
    cout << "min của vector a là: " << *min_element(a.begin(), a.end()) << endl;
 #endif
 #if 0
 for(int i=0; i<=a.size() / 2; i++){
    swap(a[i], a[a.size()-i - 1]);
 }
 cout <<  endl;
 for(int &i: a) cout << i << " ";
 #endif
 #if 0
 int sum = 0;
 for(int &i:a) sum+=i;
 // cũng có thể dùng accumulate
 // số 0 cuối hàm đóng vai trò là hệ số khởi nguyên, ví dụ a có {1,2,3} thì sum =  0 + 1+2+3
 int sum1 = std::accumulate(a.begin(), a.end(), 0);
 cout << sum << endl<< sum1 << endl;
 #endif
 #if 0
 int num = 9;
 auto it = find(a.begin(), a.end(), num);
 if(it != a.end()){
   cout<< endl << "số " << num << " được tìm thấy ở vị trí " << a.size() - (a.end() - it) +  1<< endl;
 } else  cout << "\nko tìm thấy số " << num;
 #endif
 #if 0
   int num;
   cout << "nhập số cần xóa khỏi vector..."; cin >> num;
   auto it = find(a.begin(), a.end(), num);
   while(it != a.end()){
      if(it != a.end()) a.erase(it);
      it = find(a.begin(), a.end(), num);
   }
   for(const int &i:a) cout << " " << i; 
 #endif
 #if 0
   for(int &i:a) i*=2; // dùng for each, với biến i tham số tới từng phần tử của vector a => i đổi thì a đổi
   cout << endl;
   for(const int &i:a) cout << " " << i;
 #endif
 #if 0
 auto sum =  accumulate(a.begin(), a.end(), 0);
 sum /= (a.size());
 cout << "giá trị trung bình là: " << sum << endl;
 #endif
 #if 0
 sort(a.begin(), a.end());
 cout << endl;
 for(int &i:a){ cout << i << " "; }
 vector<int> dem(a.size());
 for(int &i:dem){ i=1; }
 int demp = 0;
 for(int i=0; i<a.size(); i++){
  if(a[i]!=a[i+1]){
    demp++;
    dem[i]=demp;
    demp=0;
  } else demp++;
 }
 cout << endl;
 auto max = max_element(dem.begin(), dem.end());
 int position = max - dem.begin();
 cout << "số xuất hiện nhiều nhất là: " << a[position] << endl;
  /*
  hai iterator như max, hay dem.end() hoặc dem.begin()
  thì chỉ có trừ cho nhau, hai iterator chỉ và chỉ có thể trừ cho nhau, ý nghĩa thể hiện khoảng cách
  còn nếu cộng thì chỉ cộng cho 1 số nguyên, tức cho iterator thêm vị trí cách khoảng cách cũ bao xa 
   */
 #endif
}