class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int i=0,j=0,mx=0,sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            if(s.count(nums[j]))//if exist then remove it
            {
                 while(nums[i]!=nums[j])
                 {
                     s.erase(nums[i]);
                     sum-=nums[i++];
                 }
                    s.erase(nums[i]);
                     sum-=nums[i++];
            }
            s.insert(nums[j++]);
            mx=max(sum,mx);
        }
        return mx;
    }
    
};