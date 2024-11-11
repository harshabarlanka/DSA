#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
void PrintSub(int ind,vector<int>&arr,vector<int>&path){
    if(ind==arr.size()){
        for(auto it : path){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    PrintSub(ind+1,arr,path);
    path.push_back(arr[ind]);
    PrintSub(ind+1,arr,path);
    path.pop_back();
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> path;
    PrintSub(0,arr,path);
    return 0;
}