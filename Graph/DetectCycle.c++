#include<vector>
#include<iostream>
#include<queue>
using namespace std;
bool detect(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = true;
        while (!q.empty()) {
            int val = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it : adj[val]) {
                if (!vis[it]) {
                    q.push({it, val});
                    vis[it] = true;
                } else if (it != parent) {
                    return true;
                }
            }
        }
        return false;
}
bool detect1(int node,int parent,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node] = true;
        for(auto it : adj[node]){
            if(vis[it]==false){
                detect1(it,node,adj,vis);
            } else if(parent!=it){
                return true;
            }
        }
        return false;
}
int main(){
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
    cout << detect(0,adj,vis) << endl;
    cout << detect1(0,-1,adj,vis) << endl;
    return 0;
}