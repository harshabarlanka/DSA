#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
bool PrintSumSub(int ind,vector<int>&arr,vector<int>&path,int sum){
    if(sum==0){
        for(auto it : path){
            cout<<it<<" ";
        }
        cout<<endl;
        return true;
    }
    if(ind==arr.size() || sum<0){
        return 0;
    }
    int pick=0,notPick=0;
    if(sum>=arr[ind]){
        path.push_back(arr[ind]);
        if(PrintSumSub(ind+1,arr,path,sum-arr[ind]) == true){
            return true;
        }
        path.pop_back();
    }
    if(PrintSumSub(ind+1,arr,path,sum) == true) return true;
    return false;
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
    PrintSumSub(0,arr,path,sum);
    return 0;
}
