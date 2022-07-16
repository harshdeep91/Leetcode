class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // bool m[100001]={0};
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])//means it is repeated increase it
            {
                count+= nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
            // cout<<nums[i]<<" ";
        }
        return count;
    }
};