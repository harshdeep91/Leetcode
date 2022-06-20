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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       if(root)
       {
           root->left=trimBST(root->left,low,high);
           root->right=trimBST(root->right,low,high);
           //if value is in range means both left and right child will go up
           //if not then only single child will go up because of binary search tree
           if(root->val>=low&&root->val<=high)
               return root;
           else if(root->val<low)
               return root->right;
           else if(root->val>high)
               return root->left;
       }
        return 0;
    }
};