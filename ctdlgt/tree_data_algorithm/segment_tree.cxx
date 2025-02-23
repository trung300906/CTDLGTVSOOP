#include <bits/stdc++.h>
using namespace std;
const int Maxint = 1e6 + 1;

class segment_tree
{
    map<pair<int, int>, vector<int>> data;

public:
    void build(int left, int right, const vector<double> &data_raw)
    {
        data.insert({{left, right}, {}});
        for (int i = left; i <= right; i++)
        {
            data[{left, right}].push_back(data_raw[i]);
        }
        if (left == right)
        {
            return;
        }
        build(left, (left + right) / 2, data_raw);
        build(((left + right) / 2) + 1, right, data_raw);
    }
    void output()
    {
        int count = 1;
        for (auto &i : data)
        {
            cout << "node: " << count << endl;
            cout << "left: " << i.first.first << " right: " << i.first.second << " is: ";
            for (auto &j : i.second)
            {
                cout << j << " ";
            }
            cout << endl
                 << endl;
            count++;
        }
    }
};
int main()
{
    srand(time(NULL));
    vector<double> a;
    for (int i = 0; i < 10; i++)
    {
        a.push_back(i * (rand() % 100 + 1) - i + (1 / (i + 1)) * (i * rand() % 100 + 1));
    }
    for (auto &i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    segment_tree mytree;
    mytree.build(1, a.size(), a);
    mytree.output();
    // build segment_tree
}