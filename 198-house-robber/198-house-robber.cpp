class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=nums[0],prevprev=0,curr,i=1;
        if(nums.size()==1)
            return prev;
        while(i<nums.size())
        {
            curr=max(prev,prevprev+nums[i]);
            prevprev=max(prev,prevprev);
            prev=curr;
            i++;
        }
        return curr;
    }
};