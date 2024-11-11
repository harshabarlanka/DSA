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
void TopView(Node* root,vector<int>&res){
    if(!root) return;
    queue<pair<Node*,int>>q;
    set<int>st;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int level = it.second;
        if(st.find(level)==st.end()){
            res.push_back(node->data);
            st.insert(level);
        }
        if(node->left){
            q.push({node->left,level-1});
        }
        if(node->right){
            q.push({node->right,level+1});
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
    TopView(root,res);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}