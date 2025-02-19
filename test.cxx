#include <bits/stdc++.h>
using namespace std;

int foo()
{
    if (true)
        return 42;
}
int main()
{
    void *ptr = malloc(10);
    int *p = (int *)ptr; // Ép kiểu tường minh
    cout << *p;          // Truy cập không hợp lệ, cần khởi tạo giá trị cho `p`
    free(ptr);           // Giải phóng bộ nhớ tránh rò rỉ
    foo();
}
