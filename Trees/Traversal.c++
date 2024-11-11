#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val),left(nullptr),right(nullptr){}
};
void pre(Node* root,vector<int>&ans){
    if(!root) return;
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}
void in(Node* root,vector<int>&ans){
    if(!root) return;
    ans.push_back(root->data);
    in(root->left,ans);
    in(root->right,ans);
}
void post(Node* root,vector<int>&ans){
    if(!root) return;
    ans.push_back(root->data);
    post(root->left,ans);
    post(root->right,ans);
}
vector<int>Traversal(Node* root){
    vector<int> ans;
    pre(root,ans);
    return ans;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int>res = Traversal(root);
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<endl;
}