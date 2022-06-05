class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        int k=nums.size();
       do
        {
            for(int i=0;i<k/2;i++)
            nums[i]=i&1?nums[2*i]<nums[2*i+1]?nums[2*i+1]:nums[2*i]:nums[2*i]<nums[2*i+1]?nums[2*i]:nums[2*i+1];
        } while(k/=2);
        
        return nums[0];
    }
};