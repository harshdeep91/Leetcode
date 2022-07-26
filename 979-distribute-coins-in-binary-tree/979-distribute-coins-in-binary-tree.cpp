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
    int count=0;
    // TreeNode *head=0;
public:
    int solve(TreeNode *root)
    {
        if(root)
        {
            int x=solve(root->left);
            int y=solve(root->right);
            //send the extra and required coins up
            //and process the coins comming from down;
            //if coins is extra then it is positve else if required negative
            
            int extra= root->val-1+x+y;
            count+= abs(extra);
            return extra;
            // cout<<root->val<<" "<<extra<<" "<<x<<" "<<y<<" "<<count<<endl;
        }
        return 0;
    }
    int distributeCoins(TreeNode* root) {
        //travel postorder first
        //after that send the requirment to parents
        //if parent have more then 1 coin subtract extra coins
        //moving coins from top to bottom will take 1 unit per level
        solve(root);
        return count;
    }
};