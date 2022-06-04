class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
        int i=0,j=1,count=0;
        while(j<nums.size())
        {
            if(nums[j]-nums[i]==k)
            {
                count++;
                j++,i++;
                while(j<nums.size()&&nums[j]==nums[j-1])
                    j++;
                while(i<nums.size()&&nums[i]==nums[i-1])
                    i++;
            }
            else if(nums[j]-nums[i]<k)
                j++;
            else
                i++;
            
            if(i==j)j++;
        }
        return count;
    }
};