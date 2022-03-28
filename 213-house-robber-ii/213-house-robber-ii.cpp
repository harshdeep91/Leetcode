class Solution {
public:
    int rob(vector<int>& nums) {
        //first time i fill find from index 0 included till last index excluded
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]);
         int prev0=max(nums[0],nums[1]),prevprev0=nums[0],curr0=max(prev0,prevprev0);
        int prev1=max(nums[2],nums[1]),prevprev1=nums[1],curr1=max(prev1,prevprev1);
        // cout<<1<<" "<<curr0<<" "<<curr1<<endl;
        for(int i=2;i<nums.size();i++)
        {
            if(i<nums.size()-1)
            {
                curr0=max(prev0,prevprev0+nums[i]);
                prevprev0=prev0;
                prev0=curr0;
            }
            if(i>2)
            {
                // cout<<prev1<<" "<<prevprev1<<"--";
                curr1=max(prev1,prevprev1+nums[i]);
                prevprev1=prev1;
                prev1=curr1;
                
            }
            // cout<<i<<" "<<curr0<<" "<<curr1<<endl;
        }
        
        return max(curr0,curr1);
    }
};