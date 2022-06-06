/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA,*q=headB;
        while(p&&q)
            p=p->next,q=q->next;
        if(p)
        {
            q=headA;
            while(p)  p=p->next,q=q->next;
            p=q;
            q=headB;
        }
        else
        {
            p=headB;
            while(q) p=p->next,q=q->next;
            q=p;
            p=headA;
        }
        while(p&&q&&p!=q)
        p=p->next,q=q->next;
        return p;
    }
};