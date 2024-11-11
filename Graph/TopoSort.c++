#include<vector>
#include<queue>
#include<iostream>
using namespace std;
void toposort(vector<vector<int>>&adj,vector<int>&indegree,vector<int>&res,int n){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                    if(indegree[it]==0){
                    q.push(it);
                    }
            }
        }
}
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>>adj(n);
    vector<int>res;
    vector<int>indegree(n,0);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    toposort(adj,indegree,res,n);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}