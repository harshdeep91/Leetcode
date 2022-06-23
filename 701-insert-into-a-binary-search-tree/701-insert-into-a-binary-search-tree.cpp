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
    TreeNode* insertIntoBST(TreeNode* p, int val) {
        TreeNode *root=p;
        while(root)
        {
           if(root->val>val)
           {
               if(root->left)
               root=root->left;
               else
               {
                   root->left=new TreeNode(val);
                   return p;
               }
           }
           else
           {
               if(root->right)
               root=root->right;
                else
               {
                   root->right=new TreeNode(val);
                   return p;
               }
           }
        }
        return p==0?new TreeNode(val):p;
    }
};