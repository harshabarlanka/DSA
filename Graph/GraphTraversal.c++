#include<vector>
#include<iostream>
#include<queue>
using namespace std;
void DFS(int node,vector<vector<int>>&adj,vector<bool>&vis){
    vis[node] = true;
    cout<<node<<" ";
    for(auto it : adj[node]){
        if(vis[it]==false){
            DFS(it,adj,vis);
        }
    }
}
void BFS(int node,vector<vector<int>>&adj,vector<bool>&vis){
    queue<int>q;
    q.push(node);
    vis[node]=true;
    while(!q.empty()){
            int val = q.front();
            q.pop();
            cout<<val<<" ";
            for(auto it : adj[val]){
                if(vis[it]==false){
                    vis[it] = true;
                    q.push(it);
                }
            }
    }
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
    BFS(0,adj,vis);
    DFS(0,adj,vis);
    return 0;
}