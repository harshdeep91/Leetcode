class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> v(10001,0);
        int i=0,j=0,mx=0,sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            if(v[nums[j]])//if exist then remove it
            {
                 while(nums[i]!=nums[j])
                 {
                     v[nums[i]]=0;
                     sum-=nums[i++];
                 }
                     v[nums[i]]=0;
                     sum-=nums[i++];
            }
            v[nums[j++]]=1;
            mx=max(sum,mx);
        }
        return mx;
    }
    
};