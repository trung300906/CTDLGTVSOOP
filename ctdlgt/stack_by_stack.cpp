#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    cin >> n;
    vector<int> index;
    for (int i = 1; i <= n; i++)
    {
        index.push_back(rand() % 4 + 1); // Giới hạn nhỏ để dễ kiểm tra
    }

    for (auto &i : index)
        cout << i << ' ';
    cout << endl;

    vector<int> path(index.size());
    function<void(vector<int> &, vector<int> &, int, int)> recursive;
    recursive = [&](vector<int> &index, vector<int> &path, int level = 0, int indent = 0)
    {
        if (level == index.size())
        {
            cout << string(indent, ' ') << "[";
            for (auto &i : path)
                cout << i << " ";
            cout << "]\n";
            return;
        }

        cout << string(indent, ' ') << "[\n";
        for (int i = 0; i <= index[level]; i++)
        {
            path[level] = i;
            recursive(index, path, level + 1, indent + 2);
        }
        cout << string(indent, ' ') << "]\n";
    };
    recursive(index, path, 0, 0);
}
