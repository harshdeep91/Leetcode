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
private:
    int sum{};
    int level_so_far = 0;
    void helper(TreeNode* root, int level) {
        if(root == nullptr) {
            return ;
        }
        
        
        if(root->left == nullptr and root->right == nullptr) {
            if(level > level_so_far) {
                level_so_far = level;
                sum = root->val;
            } else if(level == level_so_far) {
                sum += root->val;
            } else return;
        }
        
        helper(root->left, level+1);
        helper(root->right, level+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        level_so_far = 0;
        sum = 0;
        helper(root,0);
        return sum;
    }
};