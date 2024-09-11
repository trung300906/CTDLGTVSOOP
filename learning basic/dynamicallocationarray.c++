#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *a = new int[5]{1, 2, 3, 4, 5}; // tạo mảng động array cho a, với 5 phần tử và các giá trị đã gán sẵn
    int *b = new int[5];                // tạo mảng động array cho b, nhưng không có phần tử sẵn
    // Lưu ý rằng mảng động phải được khai báo độ dài rõ ràng khi khởi tạo
    int *array = new int[10](); // mảng động có 10 phần tử 0
    delete[] a, b, array;
    a = nullptr;
    b = nullptr;
    array = nullptr;
    int size = 3;
    a = new int[size]{1, 2, 3};
    int newsize = 5;
    int *rea = new int[newsize];  // tạo mảng động lưu trữ lại dữ liệu của mảng động trước
    for (int i = 0; i < size; i++)
        rea[i] = a[i]; // chuyển pha dữ liệu
    delete[] a; // xóa mảng động cũ, treo mảng đó thành dialing pointer
    a = rea; // cho con trỏ từ rea chuyển ngược về a, và dùng a như bthg
    /* thực chất bạn chỉ đang sao chép địa chỉ mà con trỏ rea đang trỏ tới vào con trỏ a. Cả hai con trỏ này giờ đều cùng trỏ đến cùng một vùng nhớ. */
    size = newsize; // để lại size cho a
/*     delete[] rea;
    rea = nullptr; */
    for(int i = 0 ; i < size ; i++){
        cout << a[i] << endl;
    }
}