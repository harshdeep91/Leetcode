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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //go till depth -1
        //make new node left and right 
        // add val node and assign value
        //here levelorder is best because we need depth
        // we can use preorder also but it will runn in whole tree
        if(depth==1) return new TreeNode(val,root,0);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            depth--;
            while(size--)
            {
                TreeNode *p=q.front();
                q.pop();
                if(depth==1)//then process here
                {
                    p->left=new TreeNode(val,p->left,0);
                    p->right=new TreeNode(val,0,p->right);    
                }
                else
                {
                    if(p->left)q.push(p->left);
                    if(p->right)q.push(p->right);
                }
            }
        }
        return root;
    }
};