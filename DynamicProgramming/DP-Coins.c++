#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
//min coins denominations
int solve(vector<vector<int>>& dp, vector<int>& arr, int ind, int target){
    if(ind == 0){
        if(target % arr[0] == 0){
            return (target / arr[0]);
        } else {
            return 1e9;
        }
    }
    if(dp[ind][target] != -1){
        return dp[ind][target];
    }
    int notPick = 0 + solve(dp, arr, ind - 1, target);
    int pick = 1e9;
    if(arr[ind] <= target){
        pick = 1 + solve(dp, arr, ind, target - arr[ind]);
    }
    return dp[ind][target] = min(pick, notPick);
}

//Tabulation
int solve(vector<vector<int>>& dp, vector<int>& arr, int ind, int target){
    for(int i=0;i<target;i++){
        if(target%arr[0]==0){
            dp[0][i] = (target/arr[0]);
        } else {
            dp[0][i] = 1e9;
        }
    }
    for(int i=1;i<=ind;i++){
        int notPick,pick;
        for(int j=0;j<=target;j++){
            notPick = 0 + dp[i-1][j];
            pick = 1e9;
            if(arr[ind] <= target){
                pick = 1 + dp[i][j-arr[i]];
            }
        }
        dp[ind][target] = min(pick,notPick);
    }
    return dp[ind][target];
}

int coinDen(vector<int>& arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans = solve(dp, arr, n - 1, target);
    if(ans >= 1e9) return -1;
    else return ans;
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
    cout<<coinDen(arr,target);
    return 0;
}