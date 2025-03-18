#include <bits/stdc++.h>
using namespace std;

class insertion
{
public:
    vector<int> data;
    int n;

    insertion() // Constructor để nhập dữ liệu
    {
        cin >> n;
        data.resize(n);
        for (auto &i : data)
        {
            cin >> i;
        }
    }

    void print()
    {
        for (auto &i : data)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    void solution()
    {
        for (int i = 1; i < n; ++i) // Bắt đầu từ phần tử thứ 2
        {
            int j = i - 1;
            int key = data[i];
            while (j >= 0 && data[j] > key)
            {
                data[j + 1] = data[j];
                j -= 1;
                print();
            }
            data[j + 1] = key;
            print();
        }
    }
};

int main()
{
    insertion my_arr;
    my_arr.solution();
}
