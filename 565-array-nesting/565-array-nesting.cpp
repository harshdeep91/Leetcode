class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        int count=0,mx=0,x;
        for(int i=0;i<nums.size();i++)
        {
            count=0;
            x=nums[i];
            while(!vis[x])
            {
                count++;
                vis[x]=1;
                x=nums[x];
            }
            mx=max(count,mx);
        }
       return mx;   
    }
};