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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        while(!q.empty())
        {
            double av=0,n=q.size(),size=q.size();
            while(size--)
            {
                TreeNode *p=q.front();
                q.pop();
                av+= p->val;
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            long long int a= (av/n)*1e5;
              av= a/1e5;
            ans.push_back(av);
        }
        return ans;
    }
};