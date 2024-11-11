#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr){}
};
bool RootToNode(Node* root,vector<int>&res,int target){
    if(!root) return false;
    res.push_back(root->data);
    if(root->data == target){
        return true;
    }
    if(RootToNode(root->left,res,target) || 
    RootToNode(root->right,res,target)){
        return true;
    }
    res.pop_back();
    return false;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    vector<int> res;
    RootToNode(root,res,6);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}