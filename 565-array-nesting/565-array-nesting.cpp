class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        int count=0,mx=0,x,y;
        for(int i=0;i<nums.size();i++)
        {
            count=0;
            if(nums[i]!=-1)
            {
                x=i;
                while(nums[x]!=-1)
                {
                    count++;
                    y=x;
                    x=nums[x];
                    nums[y]=-1;;
                }
            }
            mx=max(count,mx);
        }
       return mx;   
    }
};