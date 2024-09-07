#include <iostream>
#include <vector>

using namespace std;

// Hàm đệ quy trả về vector<pair<int, int>> chứa đường đi từ startIdx đến giá trị endValue
vector<pair<int, int>> findPath(vector<pair<int, int>>& matrix, int startIdx, int endValue) {
    if (startIdx < 0 || startIdx >= matrix.size()) {
        // Nếu startIdx không hợp lệ, trả về vector rỗng
        return {};
    }

    if (matrix[startIdx].first == endValue || matrix[startIdx].second == endValue) {
        // Nếu tìm thấy giá trị cần tìm, trả về vector chứa đường đi
        return {matrix[startIdx]};
    }

    // Thử di chuyển đến các ô tiếp theo
    vector<pair<int, int>> path = findPath(matrix, startIdx + 1, endValue);

    // Nếu tìm thấy đường đi, thêm ô hiện tại vào path và trả về
    if (!path.empty()) {
        path.insert(path.begin(), matrix[startIdx]);
        return path;
    }

    // Nếu không tìm thấy đường đi, trả về vector rỗng
    return {};
}

int main() {
    vector<pair<int, int>> matrix = {
        {1,2},
        {3,2},
        {3,5},
        {4,2},
        {5,6}
    };

    int startIdx = 1;
    int endValue = 1;

    // Gọi hàm findPath để lấy kết quả
    vector<pair<int, int>> result = findPath(matrix, startIdx, endValue);

    // In kết quả ra màn hình
    for (const auto& point : result) {
        cout << "(" << point.first << ", " << point.second << ") ";
    }

    return 0;
}
