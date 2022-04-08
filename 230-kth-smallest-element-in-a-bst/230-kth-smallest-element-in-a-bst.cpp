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
    int kthSmallest(TreeNode* root, int &k) {
        
        if(root)
        {
            // cout<<k<<" "<<root->val<<endl;
            int x=kthSmallest(root->left,k);
            if(x>=0)
                return x;
            k--;
            if(k==0)
                return root->val;
            int y=kthSmallest(root->right,k);
            if(y>=0)
                return y;
            
        }
        return -1;
    }
};