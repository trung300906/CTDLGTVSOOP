#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

int findSecondLargest(const std::vector<int> &vec)
{
    // Nếu mảng rỗng hoặc chỉ có một phần tử
    if (vec.size() < 2)
    {
        return INT_MIN; // Trả về một giá trị nhỏ nếu không tìm thấy phần tử thứ hai
    }

    // Tìm phần tử lớn nhất
    int maxElement = *std::max_element(vec.begin(), vec.end());

    // Khởi tạo phần tử lớn thứ hai
    int secondMax = INT_MIN;

    // Tìm phần tử lớn thứ hai khác maxElement
    for (int num : vec)
    {
        if (num != maxElement && num > secondMax)
        {
            secondMax = num;
        }
    }

    return secondMax;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto &i : vec)
        std::cin >> i;
    int secondLargest = findSecondLargest(vec);

    if (secondLargest != INT_MIN)
    {
        std::cout << secondLargest << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }

    return 0;
}
