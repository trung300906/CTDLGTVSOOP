#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 1, b = 5;
    /*     auto check = [](auto x, auto y){
            return x>y?false: true;
        }; */
    auto lambda = [](int x, int y) -> bool
    {
        return x > y ? false : true;
    };
    decltype(lambda) check = lambda;
    /* Nếu bạn không muốn sử dụng auto và vẫn muốn khai báo biến check với kiểu dữ liệu chính xác của lambda function, bạn cần sử dụng kiểu của lambda function mà trình biên dịch tạo ra. Trong C++, kiểu của lambda function không phải là một kiểu dữ liệu đơn giản như int hay bool, mà là một kiểu đặc biệt mà trình biên dịch tạo ra. Để xác định kiểu của lambda function chính xác, bạn cần phải sử dụng kỹ thuật decltype để lấy kiểu của lambda function. */
    /* Lambda function trong C++ có kiểu đặc biệt, được gọi là kiểu lambda closure, và loại kiểu này không thể được xác định một cách trực tiếp bằng các kiểu dữ liệu đơn giản như int hay bool. */
    bool result = check(a, b);
    cout << result << endl; // Outputs: 1
    return 0;
}