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
    int mx=0,count=0;
    TreeNode *ans=0;
public:
    void solve(TreeNode* root,int level)
    {
        if(root)
        {
            solve(root->left,level+1);
            solve(root->right,level+1);
            if(level>mx)
            {
                mx=level;
                count=0;
            }
            if(level==mx)//means this is the last nodes return its root 
                count++;
            // cout<<root->val<<" "<<count<<" "<<mx<<endl;
        }
    }
    int solve2(TreeNode* root,int level)
    {
        if(root)
        {
            int x=solve2(root->left,level+1);
            int y=solve2(root->right,level+1);
            x+=(level==mx);//this node must be included
            if(x+y==count)//means this is the ans
            {
                ans=root;
                count=-1;
                return 0;
            }
            else if(x||y)//if any one node includes the count
            {
                return x+y;
            }
            // cout<<root->val<<" "<<count<<" "<<mx<<endl;
        }
        return 0;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //first of all find deepest nodes
        //return that subtree //check on other side if we got any deepest subtree
        //this is levelorder traversal we need to find max level 
        //first find max level then simply push all the nodes that are coming in that
        solve(root,0);//this will help us to count deep nodes
        // cout<<count<<" "<<mx;
        solve2(root,0);
        return ans;
    }
};