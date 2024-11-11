#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
int PrintSumSub(int ind,vector<int>&arr,vector<int>&path,int sum){
    if(sum==0){
        for(auto it : path){
            cout<<it<<" ";
        }
        cout<<endl;
        return 1;
    }
    if(ind==arr.size() || sum<0){
        return 0;
    }
    int pick=0,notPick=0;
    if(sum>=arr[ind]){
        path.push_back(arr[ind]);
        pick = PrintSumSub(ind+1,arr,path,sum-arr[ind]);
        path.pop_back();
    }
    notPick = PrintSumSub(ind+1,arr,path,sum);
    return pick+notPick;
}
int main(){
    int n,sum;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> path;
    cin>>sum;
    cout<<PrintSumSub(0,arr,path,sum);
    return 0;
}




