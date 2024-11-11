#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<set>
using namespace std;
void SubSetSum(int ind,int sum,vector<int>&arr,vector<int>&path,set<vector<int>>&res){
    if(ind==arr.size()){
        sort(path.begin(),path.end());
        res.insert(path);
        return;
    }
    SubSetSum(ind+1,sum,arr,path,res);
    path.push_back(arr[ind]);
    SubSetSum(ind+1,sum+arr[ind],arr,path,res);
    path.pop_back();
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> path;
    set<vector<int>> res;
    SubSetSum(0,0,arr,path,res);
    for(auto path : res){
        for(auto it : path){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}