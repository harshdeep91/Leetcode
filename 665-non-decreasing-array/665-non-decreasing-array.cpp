class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool up=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                //two choice nums[i]=> nums[i-1]||nums[i+1]
                if(up)return 0;
                if(i-1>=0)
                {if(nums[i-1]<=nums[i+1])//then ther is no problem
                     nums[i]=nums[i-1];
                else
                    nums[i+1]=nums[i];
                i--;}
                up=1;
                
            }
        }
        return 1;
    }
};