#include<vector>
#include<queue>
#include<iostream>
using namespace std;
vector<int>Dist(vector<vector<pair<int,int>>>&adj,int n,int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>dis(n,1e9);
    dis[source]=0;
    pq.push({0,source});
    while(!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for(auto it : adj[node]){
            int edgweight = it.second;
            int nodes = it.first;
            if(dis[nodes]>edgweight+distance){
                dis[nodes] = edgweight+distance;
                pq.push({dis[nodes],nodes});
            }
        }
    }
    return dis;
}
int main(){
    int n,e,s;
    cin>>n>>e;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    cin>>s;
    vector<int> res = Dist(adj,n,s);
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}