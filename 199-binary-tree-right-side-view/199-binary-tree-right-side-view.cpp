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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        if(!root)
            return v;
        TreeNode *p;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                p=q.front();
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
                v.push_back (p->val);
        }
        return v;
        
    }
};