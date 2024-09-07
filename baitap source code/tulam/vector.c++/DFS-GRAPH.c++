#include<bits/stdc++.h>
using namespace std;

const int MaxN = 1 + 1e5;

int n;
bool mark[MaxN];
vector<int> adj[MaxN];

void DFS(int u){
    cout << u << " ";
    mark[u] = 1;
    for(int v : adj[u]){
        if(!mark[v]) DFS(v);
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        int u, v;
        cin >> u >> v;
        // adj[u] là tập tất cả các đỉnh kề u
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < MaxN; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << i << " -- " << adj[i][j] << endl;
        }
    }
    DFS(1);

    return 0;
}
