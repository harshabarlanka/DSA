#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int lcs(int ind1,int ind2,string s1,string s3,vector<vector<int>>&dp){
    if(ind1==0 || ind2==0){
        return 0;
    }
    if(!dp[ind1][ind2]){
        return dp[ind1][ind2];
    }
    if(s1[ind1-1]==s3[ind2-1]){
        dp[ind1][ind2] =  1 + lcs(ind1-1,ind2-1,s1,s3,dp);
    } else {
        dp[ind1][ind2] = max(0+lcs(ind1-1,ind2,s1,s3,dp),0+lcs(ind1,ind2-1,s1,s3,dp));
    }
    return dp[ind1][ind2];
}
int PalindromeSub(string s1,string s3){
    int n1 = s1.size();
    int n2 = s3.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    return lcs(n1,n2,s1,s3,dp);
}
int main(){
    string s1,s3;
    cin>>s1;
    s3 = s1;
    reverse(s3.begin(),s3.end());
    cout<<PalindromeSub(s1,s3);
    return 0;
}