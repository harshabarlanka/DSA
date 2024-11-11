#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
//Partition DP Minimum Cost to Cut the Stick
int solve(vector<vector<int>>&dp,vector<int>&arr,int i,int j){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int  mini = 1e9;
    for(int ind = i;ind<=j;ind++){
        int ans = arr[j+1] - arr[i-1] + 
                  solve(dp,arr,i,ind-1) + 
                  solve(dp,arr,ind+1,j);
        mini = min(mini,ans);
    }
    return dp[i][j] = mini;
}
int partition(vector<int>&arr,int n,int c){
    arr.push_back(n);
    arr.insert(arr.begin(),0);
    sort(arr.begin(),arr.end());
    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    return solve(dp,arr,1,c);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin>>k;
    cout<<partition(arr,n,k);    
    return 0;
}