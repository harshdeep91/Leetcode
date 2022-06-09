class Solution {
public:
    int dfs(int i,vector<int> adj[],vector<int> &vis)
    {
        vis[i]=1;
        int count=0;
        for(auto x:adj[i])
            if(!vis[x])
                count=max(dfs(x,adj,vis)+1,count);
        return count;
    }
    int arrayNesting(vector<int>& nums) {
        vector<int> adj[nums.size()],vis(nums.size(),0);
        int count=0;
        for(int i=0;i<nums.size();i++)
            adj[i].push_back(nums[i]);
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[i])
            count=max(dfs(i,adj,vis)+1,count);
        }
     return count;   
    }
};