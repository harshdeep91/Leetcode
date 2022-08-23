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
    bool isPalindrome(ListNode* head) {
        //reverse the linked list in half
        //ans start traveling both linked list
        ListNode* f=head,*s=head,*p=head,*q=0,*r=0;
        bool odd=0;
        while(s)
        {
            f=f->next;
            s=s->next;
            if(s)s=s->next;
            else odd=1;
        }
        //f will point on second head
        //reverse
        while(p!=f)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        s=f,f=q;
        if(odd)f=f->next;
        while(f&&s&&f->val==s->val)
        {
            f=f->next;
            s=s->next;
        }
        return !(f||s);
    }
};