#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* root) {
    if(root->left == NULL && root->right == NULL) return true;
    else return false;
}

void leftSide(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) res.push_back(curr->data); // Add only non-leaf nodes
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

void BottomSide(Node* root, vector<int>& res) {
    if (!root) return;
    BottomSide(root->left, res);
    if (isLeaf(root)) {
        res.push_back(root->data);
    }
    BottomSide(root->right, res);
}

void rightSide(Node* root, vector<int>& res) {
    Node* curr = root->right;
    stack<int> st;
    while (curr) {
        if (!isLeaf(curr)) st.push(curr->data); // Add only non-leaf nodes
        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    vector<int> res;
    if (!isLeaf(root)) res.push_back(root->data); // Root should be included if it's not a leaf
    leftSide(root, res);
    BottomSide(root, res);
    rightSide(root, res);

    for (auto it : res) {
        cout << it << " ";
    }
    return 0;
}
