class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 2 4 
        vector<int> tmp=nums;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j)
        {
           if(tmp[i]==nums[i])
               i++;
           else if(tmp[j]==nums[j])
               j--;
            else 
                return j-i+1;
        }
            return 0;
    }
};