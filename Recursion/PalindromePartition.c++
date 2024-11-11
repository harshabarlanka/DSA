#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool isPal(string s,int s1,int e1){
    while(s1<=e1){
        if(s[s1++]!=s[e1--]){
            return false;
        }
    }
    return true;
}
void PalindromePartition(string s,int ind,vector<string>&path,vector<vector<string>>&res){
    if(ind==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(isPal(s,ind,i)==true){
            //s.substr(start,size(i-ind+1)) && +1 because 0 based index;
            path.push_back(s.substr(ind,i-ind+1));
            PalindromePartition(s,ind+1,path,res);
            path.pop_back();
        }
    }
}
int main(){
    string s;
    cin>>s;
    vector<string> path;
    vector<vector<string>> res;
    PalindromePartition(s,0,path,res);
    for(auto it : res){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}