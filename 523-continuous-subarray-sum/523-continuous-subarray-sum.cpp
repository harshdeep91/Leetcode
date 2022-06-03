class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1)return 0;
         unordered_map<int,int> rdr;
         long long sum=0;
          int  remainder;
        for(int i=0;i<nums.size();i++)
        {
             sum+=nums[i];
             remainder=sum%k;
             if(!rdr[remainder])
                 rdr[remainder]=i+1;
              if((remainder==0&&i>0)||i-rdr[remainder]+1>1)
                 return 1;
            // cout<<rdr[remainder]<<" "<<remainder<<endl;
        }
        return 0;
    }
};