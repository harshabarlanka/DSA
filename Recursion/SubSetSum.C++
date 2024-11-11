#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
void SubSetSum(int ind,int sum,vector<int>&arr,vector<int>&path){
    if(ind==arr.size()){
        path.push_back(sum);
        return;
    }
    SubSetSum(ind+1,sum,arr,path);
    SubSetSum(ind+1,sum+arr[ind],arr,path);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> path;
    SubSetSum(0,0,arr,path);
    sort(path.begin(),path.end());
    for(auto it : path){
        cout<<it<<" ";
    }
    return 0;
}