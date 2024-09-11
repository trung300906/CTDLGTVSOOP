#include <bits/stdc++.h>
using namespace std;

void dosomething()
{
    int *ptr_a = new int;
}
int main()
{
    char byte[1000000 * 2]; // lãng phí bộ nhớ
    int size = sizeof(byte);
    if (size >= 1000 * 1000)
    {
        size /= 1000 * 1000;
        cout << "Size in MB: " << size << endl;
    }
    // => nên cấp phát động cho biến nhớ
    new int; //=> con trỏ cấp phát động vùng nhớ bất kì
    int *ptr = new int;
    cout << ptr << endl; // xuất ra địa chỉ vùng nhớ cho new int
    *ptr = 10;           //  gán địa chỉ cho vùng nhớ đó = 10
    // giải phóng vùng nhớ
    delete ptr;                       // đẩy bay màu giá trị trên ptr
    int *anotherptr = ptr;            // cũng là dialing pointer
    cout << *ptr << " " << 2 << endl; // xuất ra giá trị ngẫu nhiên vì là dialing
    ptr = nullptr;                    // gán về null để không bị dialing
    /*cout << *ptr << endl;*/         // bị lỗi xuất ra giá trị(segmentation fault)
                                      // thực ra delete chả xóa cái mẹ j cả, nó chỉ đơn giản đẩy bay màu giá trị của biến pointer đó ra khỏi vùng nhớ và
                                      // và trả nó cho OS(nó thành dialing pointer), và khi ta đẩy nullptr tức là giá trị của phần đó thực sự biến mất và giá trị trên nó bị mất hoàn
                                      // toàn, và con trỏ tại đó sẽ chấm dứt trạng thái dialing(tức lơ lửng)
                                      // mún dùng lại phải gán lại cho ptr vùng nhớ khác
                                      // không cần kiểm tra con trỏ khi xóa
    // Nếu ptr không null, biến được cấp phát động sẽ bị xóa.
    // Nếu ptr là null, không có gì sẽ xảy ra.
    delete ptr;
    if (!ptr)
    {
        ptr = new int; // gán lại giá trị cấp phát lại bộ nhớ cho nó
        *ptr = 20;     // gán lại giá trị cho biến
    }
    delete ptr;
    ptr = nullptr;
    dosomething();
    // cũng bị rò rỉ bộ nhớ do vx chưa được hoàn cho windows mà chương trình cũng đéo dùng được vùng nhớ đó
    ptr = new int;
    cout << ptr << " " << 3 << endl;
    int anotherptr_2;
    ptr = &anotherptr_2; // memory leak do mất địa chỉ vùng nhớ trước mà vùng nhớ đó vx chưa được trả cho OS
    cout << ptr << " " << 4 << endl;
    ptr = new int; // cũng bị rò rỉ
    delete ptr;
    ptr = nullptr;
    return 0;
}