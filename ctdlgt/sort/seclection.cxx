#include <bits/stdc++.h>
using namespace std;

class seclection_sort
{
private:
    vector<int> data;
    int n;

public:
    seclection_sort()
    {
        cin >> n;
        data.resize(n);
        for (auto &i : data)
        {
            cin >> i;
        }
    }
    vector<int> solution()
    {
        for (int i = 0; i < n - 1; i++)
        {
            auto min = min_element(data.begin() + i, data.end());
            if (data[i] != *min) // Kiểm tra xem có hoán đổi không
            {
                swap(data[i], *min);
                for (auto &i : data)
                    cout << i << " ";
                cout << "\n";
            }
        }
        return this->data;
    }
};
int main()
{
    seclection_sort my_arr;
    my_arr.solution();
}
