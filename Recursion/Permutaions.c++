#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
void Permutations(vector<int>&arr,vector<int>&path,vector<vector<int>>&res,vector<int>&freq){
    if(path.size()==arr.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(freq[i]==0){
            freq[i]=1;
            path.push_back(arr[i]);
            Permutations(arr,path,res,freq);
            path.pop_back();
            freq[i]=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>path;
    vector<int> freq(n,0);
    vector<vector<int>> res;
    Permutations(arr,path,res,freq);
    for(auto it : res){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}