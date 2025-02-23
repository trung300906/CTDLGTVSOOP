#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Định nghĩa giá trị vô cùng

class Floyd_Warshall
{
    vector<vector<int>> maps;
    int node;

public:
    Floyd_Warshall(int n) : node(n)
    {
        maps.resize(node, vector<int>(node, INF));
        cout << "Input the weight matrix (use " << INF << " for infinity):" << endl;
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                cin >> maps[i][j];
                if (i == j) maps[i][j] = 0; // Đường đi từ một đỉnh đến chính nó luôn là 0
            }
        }
    }

    void build()
    {
        for (int k = 0; k < node; k++)
        {
            for (int i = 0; i < node; i++)
            {
                for (int j = 0; j < node; j++)
                {
                    if (maps[i][k] < INF && maps[k][j] < INF) // Tránh tràn số
                    {
                        maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);
                    }
                }
            }
        }
    }

    friend ostream &operator<<(ostream &out, const Floyd_Warshall &obj)
    {
        for (int i = 0; i < obj.node; i++)
        {
            for (int j = 0; j < obj.node; j++)
            {
                if (obj.maps[i][j] == INF)
                    out << "INF ";
                else
                    out << obj.maps[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Floyd_Warshall obj(n);
    obj.build();
    cout << "Shortest paths between all pairs of nodes:" << endl;
    cout << obj;

    return 0;
}