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
    Node *merge(Node *last,Node *second)
    {
        //merge operation
        if(last)//for root
        {
            last->next=second;
            second->prev=last;
            last->child=0;
        }
        last=second;
        second=second->next;//shifting second 
        if(last->child)//merging childs first
            last=merge(last,last->child);
        if(second)//merging next val after child
        last=merge(last,second);
        return last;//returning last pointer
    }
    Node* flatten(Node* head) {
        if(head) merge(0,head);
        return head;
    }
};