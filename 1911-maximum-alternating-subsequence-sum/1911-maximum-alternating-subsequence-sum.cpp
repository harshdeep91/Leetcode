class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
      vector<int> ans;
         ans.push_back(nums[0]);
        // [4,2,5,3]
        // 4
        //4,2
        //4,2,5
        //4,2,5
         for(int i=1;i<nums.size();i++)
         {
             if(nums[i]>ans.back())
             {
                 if(ans.size()&1)//odd means last element is even
                 ans[ans.size()-1]=nums[i];
                 else
                 ans.push_back(nums[i]);
             }
             else
             {
                 if(ans.size()&1)//odd
                 ans.push_back(nums[i]);
                 else
                 ans[ans.size()-1]=nums[i];
             }
         }
         if(!(ans.size()&1))ans.pop_back();
         long long sum=0;
         for(int i=0;i<ans.size();i++)
          if(i&1)//odd
          sum-=ans[i];
          else
          sum+=ans[i];
          return sum;
    }
};