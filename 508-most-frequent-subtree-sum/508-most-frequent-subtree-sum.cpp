class Solution {
public:
    unordered_map<int,int> um;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sum(root);
        map<int,vector<int>> mp;
        
        for(auto it : um)
            mp[it.second].push_back(it.first);
        
        
        return mp.rbegin()->second;
    }
    
    int sum(TreeNode* root){
        if(!root) return 0;
        int s =  (root->val) + sum(root->left) +  sum(root->right);
        um[s]++;
        return s;
    }
};