/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)     {
        static bool flag=0;
        if(root)
        {
            TreeNode *x=lowestCommonAncestor(root->left,p,q);
            TreeNode *y=lowestCommonAncestor(root->right,p,q);
            if(root==p||root==q||(x&&y))
                return root;
                return x?x:y;
        }
        return 0;
    }
};