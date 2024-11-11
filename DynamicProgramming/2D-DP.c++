#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
  if (dp[day][last] != -1) return dp[day][last];
  int maxi = 0;
  if(day==0){
    for(int i=0;i<3;i++){
      maxi = max(maxi,points[0][i]);
    }
    return dp[day][last] = maxi;
  }
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }
 return dp[day][last] = maxi;
}

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
  if (day < 0) return 0;  
  if (dp[day][last] != -1) return dp[day][last];
  int maxi = 0;
  for (int i = 0; i < 3; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return f(n - 1, 3, points, dp);
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>>points(n,vector<int>(3));
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
      cin>>points[i][j];
    }
  }
  cout<<ninjaTraining(n-1,points);
  return 0;
}