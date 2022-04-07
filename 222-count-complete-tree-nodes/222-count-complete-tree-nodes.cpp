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
    int mx,mxv;
    int countNode(TreeNode* root,int count,int h)
    {
        
        if(root)
        {
            // cout<<h<<" "<<count<<" "<<root->val<<endl;
            if(countNode(root->right,count*2+1,h+1))
                return 1;
            if(countNode(root->left,count*2,h+1))
                return 1;
            if(h==mx)
            {
                mxv=count;
                return 1;
            }
        }
        return 0;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        mx=1;
        mxv=1;
        TreeNode *p=root;
        while(p)
        {
            mx++;
            p=p->right;
        }
            mxv=pow(2,mx-1)-1;
       countNode(root,1,1);
        return mxv;
    }
};