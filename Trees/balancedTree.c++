#include <vector>
#include <iostream>
#include <cmath> 
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int balanced(Node* root) {
    if(!root) return 0;
    auto l = balanced(root->left);
    if(l==-1) return -1;
    auto r = balanced(root->right);
    if(r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return 1+max(l,r);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    
    if (balanced(root) == -1) {
        cout << "Not Balanced";
    } else {
        cout << "Balanced Tree";
    }
    return 0;
}
