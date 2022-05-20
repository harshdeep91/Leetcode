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
        // if(last)
        //     cout<<last->val<<" "<<second->val<<endl;
        //merge operation
        if(last)//for root
        {
            last->next=second;
            second->prev=last;
            last->child=0;
        }
        last=second;
        second=second->next;
        if(last->child)
        {
            last=merge(last,last->child);
        }
        if(second)
        last=merge(last,second);
        return last;
    }
    Node* flatten(Node* head) {
        if(head)
            merge(0,head);
        // while(head)
        // {
        //     cout<<head->val<<" ";
        //     if(head->child)
        //         cout<<head->child->val<<"child ";
        //     if(head->prev)
        //         cout<<head->prev->val<<" ";
        //     cout<<endl;
        //     head=head->next;
        // }
        return head;
    }
};