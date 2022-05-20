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
    ListNode* reverse(ListNode* l)
    {
        ListNode* p=l,*q=0,*r=0;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1),l2=reverse(l2);
        ListNode *p=l1,*q=l2,*t,*last=0,*head=0;
        int carry=0,sum;
        while(p&&q)
        {
            sum=p->val+q->val+carry;
            carry=sum/10;
            t=new ListNode(sum%10);
            if(!head)
                head=t;
            else
                last->next=t;
            last=t;
            p=p->next;
            q=q->next;
        }
        while(p)
        {
            sum=p->val+carry;
            carry=sum/10;
            t=new ListNode(sum%10);
            last->next=t;
            last=t;
            p=p->next;
        }
        while(q)
        {
            sum=q->val+carry;
            carry=sum/10;
            t=new ListNode(sum%10);
            last->next=t;
            last=t;
            q=q->next;
        }
        while(carry)
        {
            sum=carry;
            carry=sum/10;
            t=new ListNode(sum%10);
            last->next=t;
            last=t;
        }
        last->next=0;
        head=reverse(head);
        return head;
    }
};