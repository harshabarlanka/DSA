#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void BinaryDecimal(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        int sum=0;
        int p2=1;
        string bit = to_string(arr[i]);
        for(int j=bit.size()-1;j>=0;j--){
            if(bit[j]=='1'){
                sum=sum+p2;
            }
            p2=p2*2;
        }
        arr[i] = sum;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BinaryDecimal(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}