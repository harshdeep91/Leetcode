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
    int minDepth(TreeNode* root) {
        if(root)
        {
            int x=minDepth(root->left);
            int y=minDepth(root->right);
            if(x==0&&y==0)
                return 1;
            else if(x==0||y==0)
                return x?x+1:y+1;
            else
                return x>y?y+1:x+1;
        }
        return 0;
    }
};