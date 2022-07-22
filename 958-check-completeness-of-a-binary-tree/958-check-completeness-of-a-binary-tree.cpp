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
    int mxlvl=0;
public:
    int height(TreeNode *root)
    {
        if(root)
        {
            int x=height(root->left);
            int y=height(root->right);
            return x>y?x+1:y+1;
        }
        return 0;
    }
    bool isCompleteTree(TreeNode* root) {
        //we can do it by level order traveresal we need to check if
        //there is no null in level order also null only occur after last element
        queue<TreeNode*> q;
        q.push(root);
        int h=height(root);
        while(!q.empty())
        {
            int size=q.size();
            bool flag=0;
            while(size--)
            {
                root=q.front();
                q.pop();
                if(root==0)//now every root must be zero then only complete tree
                {
                    while(!q.empty()&&q.front()==0)q.pop();
                    return q.empty();
                }
                // cout<<root->val<<" ";
                root->left?q.push(root->left):q.push(0);
                root->right?q.push(root->right):q.push(0);
            }
        }
        return 1;
    }
    // 
};