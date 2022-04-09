class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
            ans^=nums[i];
        //find that setbit where it is 0 to divide the numbers
        int count=0;
        while(ans)
        {
            if(ans>>count&1)//bit is 0
                break;
            count++;
        }
        int a,b,flag_a=0,flag_b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>>count&1)//bit is one
            {
                if(flag_a)
                a^=nums[i];
                else
                {
                    a=nums[i];
                    flag_a=1;
                }
                
            }
            else
            {
                if(flag_b)
                b^=nums[i];
                else
                {
                    b=nums[i];
                    flag_b=1;
                }
            }
        }
        return {a,b};
    }
};