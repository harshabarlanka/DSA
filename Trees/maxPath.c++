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

int MaxPath(Node* root, int &maxi) {
    if (!root) return 0;
    int l = MaxPath(root->left, maxi);
    int r = MaxPath(root->right, maxi);
    int curve = root->data + l + r;
    int line = root->data + max(l, r);
    maxi = max(maxi, max(curve, line));
    return line;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int maxi = 0;
    MaxPath(root, maxi);

    cout << "Maximum Path Sum: " << maxi << endl;
    return 0;
}
