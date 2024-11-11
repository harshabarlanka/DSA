#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int flight(vector<vector<pair<int,int>>>& adj, int n, int src, int dst, int k) {
    queue<pair<int,pair<int,int>>> pq;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    pq.push({0, {0, src}});
    
    while(!pq.empty()) {
        auto it = pq.front();
        pq.pop();
        int stops = it.first;
        int dis = it.second.first;
        int node = it.second.second;
        if(stops > k) continue;
        for(auto neighbor : adj[node]) {
            int ew = neighbor.second;
            int edNode = neighbor.first;
            if(dis + ew < dist[edNode]) {
                dist[edNode] = dis + ew;
                pq.push({stops + 1, {dist[edNode], edNode}});
            }
        }
    }   
    return dist[dst] == 1e9 ? -1 : dist[dst];
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    int src, dst, k;
    cin >> src >> dst >> k;
    cout << flight(adj, n, src, dst, k);
    return 0;
}
