#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int Maze(vector<vector<int>>&grid,pair<int,int>&src,pair<int,int>&dst){
    queue<pair<int,pair<int,int>>> pq;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    int i = src.first;
    int j = src.second;
    dist[i][j] = 0;
    pq.push({0,{i,j}});
    while(!pq.empty()){
        auto it = pq.front();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        pq.pop();
        int delRow[4] = {0,-1,0,1};
        int delCol[4] = {-1,0,1,0};
        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dist[nrow][ncol]>1+dis){
                dist[nrow][ncol] = 1+dis;
                if(nrow==dst.first && ncol==dst.second){
                    return dis+1;
                }
                pq.push({1+dis,{nrow,ncol}});
            }
        }
    }
    return -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    pair<int,int> src;
    pair<int,int> dst;
    cin>>src.first>>src.second;
    cin>>dst.first>>dst.second;
    cout<<Maze(grid,src,dst);
    return 0;
}