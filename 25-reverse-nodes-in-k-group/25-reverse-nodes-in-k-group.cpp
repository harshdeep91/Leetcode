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
    ListNode * reverse(ListNode *head)
    {
        ListNode *p=head,*q=0,*r=0;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *p=head,*h,*l,*last=0;
        head=0;
        while(p)
        {
            int val=k;
            h=p;
            while(val--&&p)
            {
                l=p;
                p=p->next;
            }
            // cout<<val<<" ";
            if(val!=-1)
            {
                if(last)
                    last->next=h;
                return head?head:h;
            }
            l->next=0;
            l=reverse(h);
            if(!head)head=l;
            else
                last->next=l;
            last=h;
        }
        return head;
    }
};