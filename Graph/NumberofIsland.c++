#include<vector>
#include<iostream>
using namespace std;
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m){
        int n1 = grid.size();
        int m1 = grid[0].size();
        vis[n][m] = 1;
        int delRow[] = {0,-1,-1,-1,0,1,1,1};
        int delCol[] = {-1,-1,0,1,1,1,0,-1};
        for(int i=0;i<8;i++){
            int nrow = n + delRow[i];
            int ncol = m + delCol[i];
            if(nrow>=0 && nrow<n1 && ncol>=0 && ncol<m1 && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                dfs(grid,vis,nrow,ncol);
            }
        }
    }
    int solve(vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m){
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(vis[i][j]==0 && grid[i][j]==1){
                        cnt++;
                        dfs(grid,vis,i,j);
                    }
            }
        }
        return cnt;
    }
    int main(){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>grid(n,vector<int>(m));
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        cout<<solve(grid,vis,n,m);
        return 0;
    }
    