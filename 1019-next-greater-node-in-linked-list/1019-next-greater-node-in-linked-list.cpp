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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *p=head;
        vector<int> ans;
        stack<int> s;
        s.push(0);
        int tmp;
        while(p)ans.push_back(p->val),p=p->next;
        
        for(int i=ans.size()-1;i>=0;i--)
        {
            while(s.size()>1&&ans[i]>=s.top())s.pop();
            
            tmp=s.top();
            s.push(ans[i]);
            ans[i]=tmp;
        }
        return ans;
    }
};