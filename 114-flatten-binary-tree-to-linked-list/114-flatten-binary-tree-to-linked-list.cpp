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
    TreeNode* solve(TreeNode* p)
    {
        if(p)
        {
            if(!p->left&&!p->right)
             return p;
            TreeNode *r=p->right,*q=solve(p->left);
                if(p->left)
                    p->right=p->left;
                p->left=0;
                if(!r)
                   return q;
            if(q)
                q->right=r;
           return solve(r);
        }
        return 0;
    }
    void flatten(TreeNode* p) {
        solve(p);
    }
};