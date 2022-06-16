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
    vector<TreeNode*>v;
    unordered_map<string,int> m;
public:
    string  solve(TreeNode* root)
    {
            string l=root->left?solve(root->left):"L";
            string r=root->right?solve(root->right):"R";
            string ans=l+"*"+to_string(root->val)+"*"+r;
            if(m.find(ans)!=m.end())
            {
                if(m[ans]==1)
                   v.push_back(root),m[ans]=2;
            }
            else 
                m[ans]=1;
            return ans;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        v.clear();
        m.clear();
        solve(root);
        // for(auto x:m)
        //     cout<<x.first<<" "<<x.second<<endl;
        return v;
    }
};