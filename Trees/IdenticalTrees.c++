#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val) : data(val),left(nullptr),right(nullptr){}
};
bool Identical(Node* root,Node* root1){
    if(root==NULL || root1==NULL){
        return root==root1;
    }
    return (root->data==root1->data) && Identical(root->left,root1->left) && Identical(root->right,root1->right);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->right = new Node(6);
    root1->left->right->right->right = new Node(8);
    cout<<Identical(root,root1);
    return 0;
}