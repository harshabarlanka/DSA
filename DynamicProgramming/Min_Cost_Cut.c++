#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int MCM(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int mini = 1e9; 

    for (int k = i; k <= j; k++) {
        int cost = (arr[j + 1] - arr[i - 1]) 
                   + MCM(arr, i, k - 1, dp)  
                   + MCM(arr, k + 1, j, dp); 
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int main() {
    int n, c;
    cin >> n >> c;
    
    vector<int> arr(c); 
    for (int i = 0; i < c; i++) {
        cin >> arr[i]; 
    }

    arr.push_back(n);        
    arr.insert(arr.begin(), 0); 
    sort(arr.begin(), arr.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
    cout << MCM(arr, 1, c, dp) << endl;

    return 0;
}
