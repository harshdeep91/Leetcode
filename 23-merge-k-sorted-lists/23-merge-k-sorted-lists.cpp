/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct cmp{
         bool operator()(ListNode* a,ListNode*b){
            return a->val>b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        ListNode *head=0,*p,*last;
        for(auto x:lists)if(x)q.push(x);
        while(!q.empty())
        {
            p=q.top();
            q.pop();
            if(!head)
                head=p;
            else last->next=p;
               last=p;
            p=p->next;
            if(p)
                q.push(p);
        }
        return head;
    }
};