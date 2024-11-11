#include <vector>
#include <iostream>
#include <cmath> 
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void MakeParent(Node* root, unordered_map<Node*, Node*>& mp) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->left) {
            q.push(node->left);
            mp[node->left] = node;
        }
        if (node->right) {
            q.push(node->right);
            mp[node->right] = node;
        }
    }
}

vector<int> AtDistanceK(Node* root, unordered_map<Node*, Node*>& mp, Node* target, int k) {
    unordered_map<Node*, bool> vis;
    queue<pair<Node*, int>> q;
    q.push({target, 0});
    vis[target] = true;
    
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (level == k) {
                vector<int> res;
                while (!q.empty()) {
                    res.push_back(q.front().first->data);
                    q.pop();
                }
                res.push_back(node->data); 
                return res;
            }
            
            if (node->left && !vis[node->left]) {
                q.push({node->left, level + 1});
                vis[node->left] = true;
            }
            if (node->right && !vis[node->right]) {
                q.push({node->right, level + 1});
                vis[node->right] = true;
            }
            if (mp[node] && !vis[mp[node]]) {
                q.push({mp[node], level + 1});
                vis[mp[node]] = true;
            }
        }
    }
    
    return {}; 
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    unordered_map<Node*, Node*> mp;
    MakeParent(root, mp);
    
    Node* target = root->left->right;
    
    int k;
    cout << "Enter distance k: ";
    cin >> k;
    
    vector<int> ans = AtDistanceK(root, mp, target, k);
    if (ans.empty()) {
        cout << "No nodes found at distance " << k << " from target node " << target->data << endl;
    } else {
        cout << "Nodes at distance " << k << " from target node " << target->data << ": ";
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
