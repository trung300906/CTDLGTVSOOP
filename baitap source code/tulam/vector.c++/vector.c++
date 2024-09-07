#include <bits/stdc++.h>
using namespace std;
int main(){
    int b[5] = {0,10,2,3,4};
    vector<int> a(b,b+5); // copy từ mảng 1 chiều b, chuyển đổi nó sang 1 vector mang tên a
    // chú ý: vector<auto> a; sẽ sinh lỗi do auto không thể động biến như động của vector
    cout<< "size " << a.size() << endl;
    cout << "cap " << a.capacity() << endl;
    a.pop_back();
    cout<< "size " << a.size() << endl;
    cout << "cap " << a.capacity() << endl;
    a.shrink_to_fit(); // cấp phát lại bộ nhớ cho vector
    cout<< "size " << a.size() << endl;
    cout << "cap " << a.capacity() << endl;
    cout << "vector trước sửa là: " << endl;
    
    for(int &i: a) cout << i << endl;
    cout << "=====================================================" << endl;
    for(int i=0; i< a.size() + 2; i++){
        if(i < a.size()) cin >> a[i];
        if (i >= a.size()){ // để thêm 1 phần tử vào cuối vector bằng push_back, phải có 1 biến dự cho push_back(x); (// x là biến dự trù)
            int x;
            cin >> x;
            a.push_back(x); // khi thêm vào bằng push_back, nó sẽ tự động tăng size của a( a.size() tự xác nó tăng lên)
            break;
        }
    }
    cout << "vector sau sửa là: " << endl;
    for(int &item:a) cout << item << endl;
    cout<< "size " << a.size() << endl;
    cout << "cap " << a.capacity() << endl; // in ra sẽ bằng capacity cũ nhân 2 lên, chiến lược nhân đôi dung lượng cũ lên
    a.shrink_to_fit(); // chỉ có shrink_to_fit and swap and shrink là có thể định lại đúng capacity của vector(giảm xuống á)
    cout<< "sau sửa bằng shrink to fit " << "cap " << a.capacity() << endl;
    a.reserve(1); // reserve chỉ có tác dụng làm tăng capacity của vector mà th, riêng resize thì cắt được giảm xuống
    cout << "sau reserve có cap: " << a.capacity() << endl; 
    a.resize(12);
    cout<< "sau resize " << a.size() << endl;
    cout << "cap " << a.capacity() << endl; 
    vector<int> c(10); // định trước là vector c có dung lượng là 10
    int n = 5;
    a.erase(a.begin() + n);
}
/*  ngoài shrink_to_fit thì còn có swap and shrink
cú pháp:
     vector<kiểu dữ liệu> (tên vector mới).swap(tên vector cũ);
*/