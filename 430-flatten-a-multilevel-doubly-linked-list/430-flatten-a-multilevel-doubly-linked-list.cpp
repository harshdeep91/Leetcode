/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
 
    Node* flatten(Node* head) {
         Node *cur = head;
        Node *tail = head;
        stack<Node*> s;
        while(cur) {
            if(cur->child ) {
                Node *child = cur->child;
                if(cur->next){ 
                    s.push(cur->next);
                    cur->next->prev = 0; 
                }
                cur->next = child;
                child->prev = cur;
                cur->child = 0;
            }
            tail = cur;
            cur = cur->next;
        }
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            tail->next = cur;
            cur->prev = tail;
            while(cur ) {
                tail = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};