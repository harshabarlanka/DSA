#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if (!root) return ans; 
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level; 
        for (int i = 0; i < size; i++) {
            Node* node = q.front(); 
            q.pop();
            level.push_back(node->data);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(level); 
    }
    return ans; 
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->right = new Node(6);
    root->right->left = new Node(9);

    vector<vector<int>> res = levelOrder(root);
    for (auto level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
