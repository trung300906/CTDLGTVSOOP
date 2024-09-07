#include<bits/stdc++.h>
using namespace std;

const int MaxN = 1 + 1e5;

int n;
bool mark[MaxN];
vector<int> adj[MaxN];

void BFS(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        mark[u] = 1;
        cout << u << " ";
        for(int v : adj[u])
        if(!mark[v]) q.push(v);
    }
}

int main(){
    /* freopen("CTDL.inp","r",stdin);
    freopen("CTDL.out","w",stdout); */
    cin >> n;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        // adj[u] là tập tất cả các đỉnh kề u
       // Khi ta thêm đỉnh v vào adj[u] có nghĩa là có cạnh trực tiếp theo hướng từ u tới v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS();

    return 0;
}
