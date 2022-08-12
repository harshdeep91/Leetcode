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
    TreeNode *ans=0;
public:
    int lca(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root)
        {
            int x= lca(root->left,p,q);
            int y= lca(root->right,p,q);
            if(ans)return 0;
            if(root==p||root==q)//return based on prev
            {
                if(x==1||y==1)//means we already got other element
                    ans=root;
                
                    return 1;
            }
            if(x==1||y==1)
            {
                if(x==1&&y==1)
                {
                    if(!ans)ans=root;
                }
                else
                    return 1;
            }
        }
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //for finding lowest common ancestor we need to 
        //travel by postorder if we got both element return the root
        //if only one return the node we found
        lca(root,p,q);
        return ans;
    }
};