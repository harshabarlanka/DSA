#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void DecimalBinary(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        string res = "";
        int n = arr[i];
        if(n==0) res='0';
        else {
            while(n>0){
                if(n%2==1) res+='1';
                else res+='0';
                n=n/2;
            }
            reverse(res.begin(),res.end());
        }
        arr[i] = stoi(res);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    DecimalBinary(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}