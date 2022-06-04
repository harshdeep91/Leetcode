class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1)return 0;
         unordered_map<int,int> rdr;
        rdr[0]=-1;
         long long sum=0;
          int  remainder;
        for(int i=0;i<nums.size();i++)
        {
             sum+=nums[i];
             remainder=sum%k;
             if(rdr.find(remainder)==rdr.end())
                 rdr[remainder]=i;
              if(i-rdr[remainder]>1)
                 return 1;
        }
        return 0;
    }
};