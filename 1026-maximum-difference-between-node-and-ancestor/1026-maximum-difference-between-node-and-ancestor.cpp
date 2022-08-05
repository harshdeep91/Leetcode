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
    int ans=0;
public:
    pair<int,int> solve(TreeNode *root)
    {
        //first = min value ,second =max value
        if(root)
        {
            pair<int,int> x=solve(root->left);
            pair<int,int> y=solve(root->right);
            int mi=min(x.first,y.first),mx=max(x.second,y.second);
            if(mi==INT_MAX||mx==INT_MIN)//means child is null
                return {root->val,root->val};
            
            ans = max(ans,max(abs(mi-root->val),abs(mx-root->val)));
            return {min(root->val,mi),max(root->val,mx)};
        }
        return {INT_MAX,INT_MIN};
    }
    int maxAncestorDiff(TreeNode* root) {
        //we can approach by brute force for every node 
        //find every child 
        //and other method could be to get max abs
        //we either need min child or max child 
        solve(root);
        return ans;
    }
};