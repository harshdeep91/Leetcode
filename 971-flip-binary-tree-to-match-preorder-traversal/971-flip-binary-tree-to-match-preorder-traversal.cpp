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
    vector<int> ans;
    int i=0;
public:
    bool solve(TreeNode *root,vector<int> &voyage)
    {
        if(root)
        {
            bool x=0;
            if(root->val==voyage[i])
            {
                i++;
                x=solve(root->left,voyage)&&solve(root->right,voyage);
                if(!x)
                {
                    ans.push_back(root->val);
                    x=solve(root->right,voyage)&&solve(root->left,voyage);
                }
            }
                  return x;     
        }
        return 1;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        //if we not match with voyage simply flip
        if(!solve(root,voyage))
        {
            // ans.push_back(-1);
            return {-1};
        }
        return ans;
    }
};