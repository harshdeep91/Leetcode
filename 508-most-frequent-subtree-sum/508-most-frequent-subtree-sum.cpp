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
    unordered_map<int,int> m;
public:
    int solve(TreeNode *root)
    {
        if(root)
        {
            int x=solve(root->left);
            int y=solve(root->right);
            int z=x+y+root->val;
            m[z]++;
            return z;
        }
        return 0;
    }
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second>b.second;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<pair<int,int>> v;
        vector<int> ans;
        m.clear();
        solve(root);
        for(auto x:m)
            v.push_back(x);
        sort(v.begin(),v.end(),cmp);
        int i=0;
        while(i==0||(i<v.size()&&v[i-1].second==v[i].second))
            ans.push_back(v[i++].first);
        return ans;
    }
};