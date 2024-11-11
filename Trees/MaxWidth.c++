#include <vector>
#include <iostream>
#include <cmath> 
#include<queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int MaxWidth(Node* root,int maxi){
    if(!root) return 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        int first,last;
        for(int i=0;i<n;i++){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            long long width = it.second;
            if(i==0) first=width;
            if(i==n-1) last=width;
            if(node->left) q.push({node->left,2*width+1});
            if(node->right) q.push({node->right,2*width+2});
        }
        maxi = max(maxi,last-first+1);
    }
    return maxi;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    int maxi = 0;
    cout<<MaxWidth(root,maxi);
    return 0;
}