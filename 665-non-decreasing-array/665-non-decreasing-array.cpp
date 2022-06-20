class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
     //it is only poss when there is only one increasing and second increasing possible
        // 4 2 3
        //check for first increasing sequence
        int i=0;
        while(i+1<nums.size()&&nums[i]<=nums[i+1])i++;
        if(i+1==nums.size())return 1;
        //suppose this is the index
        //travel left to right for this it is increasing
        
        vector<int> tmp=nums;
        bool up=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                if(up)
                {
                    up=0;
                    break;
                }
                else 
                {
                    nums[i]=i-1>=0?nums[i-1]:-1e5;
                    up=1;
                    i--;
                }
            }
        }
        if(up)return 1;
        //travel right to left for this is it decrease
        for(int i=nums.size()-1;i>0;i--)
        {
           if(tmp[i-1]>tmp[i])
            {
                if(up)return 0;
                else 
                {
                    // cout<<tmp[i]<<" ";
                    tmp[i]=i+1<tmp.size()?tmp[i+1]:1e5;
                    up=1;
                    // cout<<tmp[i]<<" ";
                    i++;
                    
                }
            }     
        }
        return 1;
    }
};