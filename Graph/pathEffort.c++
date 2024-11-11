#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int Path(vector<vector<int>>&grid,int sr,int sc){
    int n = grid.size();
    int m = grid[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{sr,sc}});
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[sr][sc]=0;
    int delRow[4] = {0,-1,0,1};
    int delCol[4] = {-1,0,1,0};
    while(!pq.empty()){
        auto it = pq.top();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        pq.pop();
        if(row == n-1 && col == m-1) return dis;
        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int effort = max(abs(grid[row][col] - grid[nrow][ncol]), dis);
                if(effort<dist[nrow][ncol]){
                    dist[nrow][ncol] = effort;
                    pq.push({effort,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<Path(grid,0,0);
    return 0;
}