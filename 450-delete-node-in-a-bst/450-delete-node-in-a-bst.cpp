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
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root)
        {
            if(root->val==key)
            {
                TreeNode *p=root;
                if(root->left)//inorder predecessor
                {
                    p=p->left;
                    while(p->right)
                        p=p->right;
                    swap(p->val,root->val);
                    root->left=deleteNode(root->left,p->val);
                     // cout<<root->val<<" "<<p->val;
                    
                }
                else if(root->right)
                {
                    p=p->right;
                    while(p->left)
                        p=p->left;
                    swap(p->val,root->val);
                    root->right=deleteNode(root->right,p->val);
                 }
                else
                {
                    // delete root;
                    return 0;
                }
            }
            else if(root->val<key)
                root->right=deleteNode(root->right,key);
            else
               root->left=deleteNode(root->left,key);
        }
       return root;
    }
                         
};