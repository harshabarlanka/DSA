#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
//DP on Longest increasing subsequence
int solve(vector<vector<int>>&dp,vector<int>&arr,int ind,int prev){
    if(ind==arr.size()){
        return 0;
    }
    if(dp[ind][prev+1]!=-1){
        return dp[ind][prev+1];
    }
    int notPick = 0;
    int pick = 0;
    notPick = 0 + solve(dp,arr,ind+1,prev);
    if(prev==-1 || arr[ind]>arr[prev]){
         pick = 1 + solve(dp,arr,ind+1,ind);
    }
    return dp[ind][prev+1] = max(notPick,pick);
}
int lis(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(dp,arr,0,-1);
}


//My Tabulation

int solve(vector<vector<int>>&dp,vector<int>&arr,int ind,int prev){
    for(int i=0;i<arr.size();i++){
        dp[arr.size()][i] = 0;
    }
    for(int i=0;i<arr.size();i++){
        dp[i][arr.size()] = 0;
    }
    for(int i=arr.size()-1;i>=0;i--){
        int notPick = 0;
        int pick = 0;
        for(int j=i-1;j>=-1;j--){
            notPick = 0 + dp[i+1][j];
            if(prev==-1 || arr[ind]>arr[prev]){
                pick = 1 + dp[i+1][i];
            }
            return dp[ind][prev+1] = max(notPick,pick);
        }
    }
    return dp[0][0];
}


// Tabulation of LIS

int lis(int n, vector<int>& arr) {
    vector<int> next(n+1, 0),curr(n+1,0);

    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= -1; j--) {
            int len = 0 + next[j+1]; 
            if (j == -1 || arr[i] > arr[j]) {
                len = max(len, 1 + next[i+1]); 
            }
            curr[j+1] = len;
        }
        next = curr;
    }
    return curr[0]; 
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << lis(n, arr) << endl;
    cout<<lis(arr);
    return 0;
}