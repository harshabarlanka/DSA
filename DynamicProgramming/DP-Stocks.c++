#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
//dp on stocks
long getAns(vector<long>&arr, int ind, int buy, int n, vector<vector<long>> &dp) {
    if (ind == n) {
        return 0;
    }
    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 0) { 
        profit = max(0 + getAns(arr, ind + 1, 0, n, dp), -arr[ind] + getAns(arr, ind + 1, 1, n, dp));
    }

    if (buy == 1) { 
        profit = max(0 + getAns(arr, ind + 1, 1, n, dp), arr[ind] + getAns(arr, ind + 1, 0, n, dp));
    }

    return dp[ind][buy] = profit;
}

long getMaximumProfit(vector<long>& arr, int n) {
    vector<vector<long>> dp(n, vector<long>(2, -1));

    if (n == 0) {
        return 0;
    }

    long ans = getAns(arr, 0, 0, n, dp);
    return ans;
}

//My Tabulation

long getAns(vector<long>&arr, int ind, int buy, int n, vector<vector<long>> &dp) {
    for(int i=0;i<arr.size();i++){
        dp[n][i] = 0;
    }
    for(int i=0;i<2;i++){
        dp[i][n] = 0;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            long profit = 0;
            if (j == 0) { 
                profit = max(0 + dp[i+1][0], -arr[i] + dp[i+1][1]);
            }
            if (j == 1) { 
                profit = max(0 + dp[i+1][1], arr[i] + dp[i+1][0]);
            }
            return dp[i][j] = profit;
        }
    }
    return dp[0][0];
}

//Tabulation on Stocks

int stock(int n,vector<int>&arr){
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            if(j==0){
                dp[i][j] = max(0+dp[i+1][0],-arr[i]+dp[i+1][1]);
            } else {
                dp[i][j] = max(0+dp[i+1][1],arr[i]+dp[i+1][0]);
            }
        }
    }
    return dp[0][0];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<stock(n,arr);
    return 0;
}