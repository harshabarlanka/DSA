#include<vector>
#include<queue>
#include<cmath>
#include<iostream>
#include<map>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val),left(nullptr),right(nullptr){}
};
void BottomView(Node* root,vector<int>&res){
    if(!root) return;
    queue<pair<Node*,int>>q;
    map<int,int>st;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int level = it.second;
        st[level] = node->data;
        if(node->left){
            q.push({node->left,level-1});
        }
        if(node->right){
            q.push({node->right,level+1});
        }
    }
    for(auto it : st){
        res.push_back(it.second);
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
    BottomView(root,res);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}