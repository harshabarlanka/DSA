#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
//longest common subsequence
int solve(vector<vector<int>>&dp,string s1,string s2,int ind1,int ind2){
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    int pick = 0;
    if(s1[ind1]==s2[ind2]){
        pick  = 1 + solve(dp,s1,s2,ind1-1,ind2-1);
    } else {
        pick = max(solve(dp,s1,s2,ind1-1,ind2),solve(dp,s1,s2,ind1,ind2-1));
    }
    dp[ind1][ind2] = pick;
}
int lcs(string s1,string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>>dp(n1,vector<int>(n2,-1));
    return solve(dp,s1,s2,n1-1,n2-1);
}

//My Tabulation

int solve(vector<vector<int>>&dp,string s1,string s2,int ind1,int ind2){
    for(int i=0;i<s1.size();i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<s2.size();i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            int pick = 0;
            if(s1[ind1]==s2[ind2]){
                pick  = 1 + dp[i-1][j-1];
            } else {
                pick = max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j] = pick;
        }
    }
    return dp[s1.size()][s2.size()];
}


//Tabulation of LCS
        //Note:-
            //Here we use the 1 based index from n1 and n2 to ind1==0 || ind2==0
            //But in c++ the strings are basically '0' based indexs so we need take care of it so thats way
            //we check like this condition s1[ind1-1] == s2[ind2-1] rather than the s1[ind1]==s2[ind2]
            
int lcs1(string s1,string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            int len = 0;
            if(s1[i-1]==s2[j-1]){
                len = max(len,1 + dp[i-1][j-1]);
            } else {
                len = max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j] = len;
        }
    }
    return dp[n1][n2];
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1,s2)<<endl;
    return 0;
}