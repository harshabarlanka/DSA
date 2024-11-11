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
int LCA(Node* root, int p, int q) {
    if (root == NULL) return -1;
    if (root->data == p || root->data == q) return root->data;
    int l = LCA(root->left, p, q);
    int r = LCA(root->right, p, q);
    if (l != -1 && r != -1) return root->data;
    return (l != -1) ? l : r;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    
    cout << LCA(root, 4, 6) << endl; 
    return 0;
}
