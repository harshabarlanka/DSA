#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Matrix Chain Multiplication

int MCM(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i >= j) return 0; // Base case

    if (dp[i][j] != -1) return dp[i][j];

    int mini = 1e9; 
    for (int k = i; k < j; k++) { 
        int steps = (arr[i - 1] * arr[k] * arr[j]) + MCM(arr, i, k, dp) + MCM(arr, k + 1, j, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini; 
}

//Tabulation

int MCM(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    for(int i=0;i<arr.size();i++){
        dp[i][i] = 0;
    } 
    int mini = 1e9; 
    for(int i=arr.size()-1;i>=1;i--){
        for(int j=i+1;j<=arr.size();j++){
            for (int k = i; k < j; k++) { 
                int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                dp[i][j] = min(mini, steps);
            }
        }
    }
    return dp[i][j]; 
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << MCM(arr, 1, n - 1, dp) << endl;
    return 0;
}
