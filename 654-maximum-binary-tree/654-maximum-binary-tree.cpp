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
    TreeNode* solve(int i,int j,vector<int> &nums)
    {
        if(j<i)return 0;
        int index=i;
        for(int k=i+1;k<=j;k++)
            if(nums[k]>nums[index])
                index=k;
        // cout<<i<<" "<<j<<nums[index]<<endl;
        TreeNode * root=new TreeNode(nums[index]);
        root->left=solve(i,index-1,nums);
        root->right=solve(index+1,j,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};