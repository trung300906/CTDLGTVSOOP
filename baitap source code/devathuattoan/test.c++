#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> w;  // Định nghĩa danh sách các cặp phần tử (cạnh)

int k;  // Giả sử k là một biến toàn cục, bạn cần định nghĩa nó ở một nơi nào đó trong chương trình của bạn.

struct strdata{
    std::pair<int, int> oupair;
    bool yet;
};
int duyet(int cur, int stridx, int dichcur, int cost) {
    if (cur == dichcur) {
        return cost;
    }

    if (cost > k) {
        return -1;
    }

    for (int i = stridx; i < w.size(); i++) {
        if (cur == w[i].first){
            int result = duyet(w[i].second, stridx+1, dichcur, cost+1);
            if(result != -1) return result;
        }
        if (cur == w[i].second) {
            int result = duyet(w[i].first, stridx+1, dichcur, cost+1);
            if(result != -1) return result;
        }
    }

    return -1;
}

int main() {
    // Example usage:
    w = {{1, 2}, {2, 3}, {3, 5}};
    k = 10;
    int result = duyet(1,0 , 5, 0);  // Gọi hàm đệ quy
    std::cout << "Result: " << result << std::endl;

    return 0;
}
