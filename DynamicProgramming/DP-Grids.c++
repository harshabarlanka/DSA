#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
//min path sum
int solve(vector<vector<int>>&dp,vector<vector<int>>points,int n,int m){
    if(n==0 && m==0) return points[0][0];
    if(n<0 || m<0){
        return 1e9;
    }
    int left = points[n][m] + solve(dp,points,n,m-1);
    int up = points[n][m] + solve(dp,points,n-1,m);
    return dp[n][m] = min(left,up);
}
int minPath(vector<vector<int>>&points,int n,int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(dp,points,n-1,m-1);
}

//Tabulation
int solve(vector<vector<int>>&dp,vector<vector<int>>points,int n,int m){
    dp[0][0] = points[0][0];
    for(int i=0;i<m;i++){
        dp[0][m] = 1e9;
    }
    for(int i=0;i<n;i++){
        dp[n][0] = 1e9;
    }
    for(int i=1;i<=n;i++){
        int left,up;
        for(int j=1;j<=m;j++){
            left = points[n][m] + dp[n][m-1];
            up = points[n][m] + dp[n-1][m];
        }
        dp[n][m] = min(left,up);
    }
    return dp[n][m];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>points(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>points[i][j];
        }
    }
    cout<<minPath(points,n,m);
    return 0;
}