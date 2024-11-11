#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};
int length(Node* slow,Node* fast){
    int cnt = 1;
    slow = slow->next;
            while(fast!=slow){
                cnt++;
                slow = slow->next;
            }
        return cnt;
}
int Solve(Node* head){
    Node* slow = head;
    Node* fast = head;
    int cnt = 1;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return length(slow,fast);
        }
    }
    return cnt;
}
int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next = node2;
    Node* node3 = new Node(3);
    node2->next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4->next = node5;
    //Loop
    node5->next = node2;
    Node* head = node1;
    cout<<Solve(head);
    return 0;
}