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
    int height(TreeNode *root)
    {
        if(root)
        {
            int x=height(root->left);
            int y=height(root->right);
            return x>y?x+1:y+1;
        }
        return -1;
    }
    void solve(int r,int c,int &m,TreeNode *root,vector<vector<string>> &ans)
    {
        if(root)
        {
             ans[r][c]=to_string(root->val);
             solve(r+1,c-pow(2,m-r-1),m,root->left,ans);
             solve(r+1,c+pow(2,m-r-1),m,root->right,ans);
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int m=height(root),n=pow(2,m+1)-1;
       vector<vector<string>> ans(m+1,vector<string>(n,""));
        solve(0,(n-1)/2,m,root,ans);
        return ans;
    }
};