#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void SortTrunksOptimized(std::vector<int> &arr)
{
    if (arr.empty())
        return;

    // Bước 1: Tìm min và max của mảng để tối ưu index
    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());

    // Bước 2: Tạo bảng tần suất
    std::vector<int> freq(maxVal - minVal + 1, 0);
    for (int num : arr)
    {
        freq[num - minVal]++;
    }

    // Bước 3: Ghi đè mảng theo thứ tự tăng dần
    int index = 0;
    for (int i = 0; i < freq.size(); ++i)
    {
        while (freq[i]--)
        {
            arr[index++] = i + minVal;
        }
    }
}

int main()
{
    std::vector<int> arr = {4, 2, 7, 7, 3, 1, 5, 10, 2, 4};
    SortTrunksOptimized(arr);

    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    return 0;
}
