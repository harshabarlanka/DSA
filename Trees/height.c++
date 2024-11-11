#include<vector>
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val) ,left(nullptr),right(nullptr){}
};
int solve(Node* root){
    if(!root) return 0;
    auto l = solve(root->left);
    auto r = solve(root->right);
    return 1 + max(l,r);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout<<solve(root);
    return 0;
}