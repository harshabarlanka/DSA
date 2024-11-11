#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
void Permutations(int ind,vector<int>&arr,vector<vector<int>>&res){
    if(ind==arr.size()){
        res.push_back(arr);
        return;
    }
    for(int i=ind;i<arr.size();i++){
        swap(arr[i],arr[ind]);
        Permutations(ind+1,arr,res);
        swap(arr[i],arr[ind]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> res;
    Permutations(0,arr,res);
    for(auto it : res){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}