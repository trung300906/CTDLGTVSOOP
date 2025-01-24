#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <sstream>

int main() {
    // Khai báo các tập hợp để lưu trữ tên package
    std::unordered_set<std::string> packagesA;
    std::unordered_set<std::string> packagesB;

    // Đọc dữ liệu từ file A
    std::ifstream fileA("/run/media/trung/14dd9ffb-8b76-4e7a-aeb9-88de409326fe/package.txt");
    if (!fileA.is_open()) {
        std::cerr << "Không thể mở fileA.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(fileA, line)) {
        std::istringstream iss(line);
        std::string packageName;
        iss >> packageName; // Lấy tên package (phần trước khoảng trắng đầu tiên)
        packagesA.insert(packageName);
    }
    fileA.close();

    // Đọc dữ liệu từ file B
    std::ifstream fileB("/home/trung/packageintstall.txt");
    if (!fileB.is_open()) {
        std::cerr << "Không thể mở fileB.txt" << std::endl;
        return 1;
    }

    while (std::getline(fileB, line)) {
        std::istringstream iss(line);
        std::string packageName;
        iss >> packageName;
        packagesB.insert(packageName);
    }
    fileB.close();

    // So sánh và in ra các package chỉ có trong file A
    std::cout << "Các package có trong file A nhưng không có trong file B:" << std::endl;
    for (const auto& package : packagesA) {
        if (packagesB.find(package) == packagesB.end()) {
            std::cout << package << std::endl;
        }
    }

    return 0;
}
