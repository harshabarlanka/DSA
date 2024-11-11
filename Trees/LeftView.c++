#include<vector>
#include<queue>
#include<cmath>
#include<iostream>
#include<set>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val),left(nullptr),right(nullptr){}
};
void LeftView(Node* root,vector<int>&res){
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node* node = q.front();
            q.pop();
            if(i==0){
                res.push_back(node->data);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    vector<int>res;
    LeftView(root,res);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}