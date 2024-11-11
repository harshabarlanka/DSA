#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
//subset sum
bool solve(vector<vector<int>>&dp,vector<int>&arr,int ind,int target){
    if(target==0) return true;
    if(ind==0){
        return arr[0]==target;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notpick =  solve(dp,arr,ind-1,target);
    bool pick = false;
    if(arr[ind]<=target){
        pick = solve(dp,arr,ind-1,target-arr[ind]);
    }
    return dp[ind][target] = pick || notpick;
}
bool subsum(vector<int>&arr,int target){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return solve(dp,arr,n-1,target);
}


//My Tabulation

bool solve(vector<vector<bool>>&dp,vector<int>&arr,int ind,int target){
    for(int i=0;i<arr.size();i++){
        dp[i][0] = true;
    }
    if(arr[0]==target){
        dp[0][arr[0]] = true;
    }
    for(int i=1;i<=arr.size();i++){
        bool notpick,pick;
        for(int j=1;j<=target;j++){
            notpick =  dp[i-1][j];
            pick = false;
            if(arr[ind]<=target){
                pick = dp[i-1][j-arr[i]];
            }
            dp[i][j] = pick||notpick;
        }
    }
    return dp[arr.size()][target];
}

//Tabulation
bool subset(vector<int>&arr,int target){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(arr[0]<=target){
        dp[0][arr[0]] = true;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(arr[i]<=target){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take || notTake;
        }
    }
    return dp[n-1][target];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin>>target;
    if(subset(arr,target)){
        cout<<"Possible";
    } else {
        cout<<"Not Possible";
    }
    return 0;
}