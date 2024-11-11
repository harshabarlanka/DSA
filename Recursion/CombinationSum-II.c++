#include<vector>
#include<cmath>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
void PrintSumSub(int ind,vector<int>&arr,vector<int>&path,int sum,set<vector<int>>&res){
    if(sum==0){
        sort(path.begin(),path.end());
        res.insert(path);
    }
    if(ind==arr.size() || sum<0){
        return;
    }
    int pick=0,notPick=0;
    if(sum>=arr[ind]){
        path.push_back(arr[ind]);
        PrintSumSub(ind+1,arr,path,sum-arr[ind],res);
        path.pop_back();
    }
    PrintSumSub(ind+1,arr,path,sum,res);
}
int main(){
    int n,sum;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> path;
    set<vector<int>>res;
    cin>>sum;
    PrintSumSub(0,arr,path,sum,res);
    for(auto it : res){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}