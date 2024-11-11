#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
//distinct subsequence
int solve(vector<vector<int>>&dp,string s1,string s2,int ind1,int ind2){
    if(ind2==0){
        return 1;
    }
    if(ind1==0){
        return 0;
    }
    int res = 0;
    if(s1[ind1-1] == s2[ind2-1]){
        int leave = solve(dp,s1,s2,ind1-1,ind2-1);
        int stay = solve(dp,s1,s2,ind1-1,ind2);
        res = leave+stay;
    } else {
        res = solve(dp,s1,s2,ind1-1,ind2);
    }
    dp[ind1][ind2] = res;
}
int dist(string s1,string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    return solve(dp,s1,s2,n1,n2);
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<dist(s1,s2);
    return 0;
}