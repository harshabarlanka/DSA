#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis) {
    vis[node] = true;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(adj, it, vis);
        }
    }
}

int province(vector<vector<int>>& adj, int n, vector<bool>& vis) {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(adj, i, vis);
        }
    }
    return cnt;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << province(adj, n, vis) << endl;
    return 0;
}
