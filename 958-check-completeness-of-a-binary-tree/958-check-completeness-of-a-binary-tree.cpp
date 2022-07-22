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
    bool isCompleteTree(TreeNode* root) {
        //we can do it by level order traveresal we need to check if
        //there is no null in level order also null only occur after last element
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                root=q.front();
                q.pop();
                if(root==0)//now every root must be zero then only complete tree
                {
                    while(!q.empty()&&q.front()==0)q.pop();
                    return q.empty();
                }
                root->left?q.push(root->left):q.push(0);
                root->right?q.push(root->right):q.push(0);
            }
        }
        return 1;
    }
    // 
};