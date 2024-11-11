#include<vector>
#include<queue>
#include<iostream>
using namespace std;
bool bipartite(vector<vector<int>>&adj,int node,vector<bool>&vis,vector<int>&cols){
        queue<int> q;
        q.push(node);
        vis[node]=true;
        cols[node]=0;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(auto it : adj[val]){
                if(vis[it]==false){
                    vis[it]=true;
                    cols[it] = !cols[val];
                } else if(cols[it]==cols[val]){
                    return false;
                }
            }
        }
        return true;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[u].push_back(u);
    }
    vector<int>col(n);
    vector<bool>vis(n,false);
    cout<<bipartite(adj,0,vis,col);
    return 0;
}