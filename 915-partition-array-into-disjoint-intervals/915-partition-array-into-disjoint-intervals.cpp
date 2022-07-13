class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
      vector<int> lMax=nums,rMin=nums;
      for(int i=1;i<nums.size();i++)
        lMax[i]=(nums[i]>lMax[i-1])?nums[i]:lMax[i-1];
       for(int i=nums.size()-2;i>=0;i--)
        rMin[i]=(nums[i]<rMin[i+1])?nums[i]:rMin[i+1];
        for(int i=0;i<nums.size()-1;i++)
            if(lMax[i]<=rMin[i+1])return i+1;
        return 0;
    }
};