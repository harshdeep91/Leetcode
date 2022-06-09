class Solution {
public:
    int dfs(int i,vector<int> &nums,vector<int> &vis)
    {
        vis[i]=1;
        if(!vis[nums[i]])
        return dfs(nums[i],nums,vis)+1;
        else
            return 0;
    }
    int arrayNesting(vector<int>& nums) {
        vector<int> adj[nums.size()],vis(nums.size(),0);
        int count=0;
        for(int i=0;i<nums.size();i++)
            adj[i].push_back(nums[i]);
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[nums[i]])
                count=max(dfs(nums[i],nums,vis)+1,count);
            
        }
     return count;   
    }
};