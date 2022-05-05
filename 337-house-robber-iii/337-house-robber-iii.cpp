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
    pair<int,int> solve(TreeNode *p)
    {
        if(p)
        {//first=including that node //second exluding that node
            pair<int,int> x=solve(p->left);
            pair<int,int> y=solve(p->right);
            int second=max(x.first,x.second)+max(y.first,y.second);
            int first=p->val+x.second+y.second;
            return {first,second};
        }
        return {0,0};
    }
    int rob(TreeNode* root) {
        //max(p->left,p->right)
        pair<int,int> ans=solve(root);
        return ans.first>ans.second?ans.first:ans.second;
    }
};