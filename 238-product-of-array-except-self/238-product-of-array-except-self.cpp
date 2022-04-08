class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> dpf(nums.begin(),nums.end()),dpl(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            dpf[i]*=dpf[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            dpl[i]*=dpl[i+1];
        }
        nums[0]=dpl[1];
        nums[nums.size()-1]=dpf[nums.size()-2];
        for(int i=1;i<nums.size()-1;i++)
        {
            
            nums[i]=dpf[i-1]*dpl[i+1];
        }
        return  nums;
    }
};