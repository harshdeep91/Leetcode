/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head=new TreeNode(preorder[0]),*t;
        stack<TreeNode*> s;
        s.push(head);
        for(int i=1;i<preorder.size();i++)
        {
            // cout<<i<<" ";
            t=new TreeNode(preorder[i]);
            if(t->val<s.top()->val)
            {
                s.top()->left=t;
            }
            else
            {
                //we need to check if this element is greater then parrent also or not
                //if yes then it is placed in right of s.top();
                TreeNode * curr=s.top();
                s.pop();
                while(s.size()&&s.top()->val<t->val)
                {
                    curr=s.top();
                    s.pop();
                }
                curr->right=t;
            }
                s.push(t);
        }
        return head;
    }
};