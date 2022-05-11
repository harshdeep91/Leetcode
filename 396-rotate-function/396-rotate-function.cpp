class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
         int sum = 0,p = 0;
       for(int i = 0;i<nums.size();i++)
       {
           sum += nums[i];
           p += (i*nums[i]);
       }
       int mx = p;
        // cout<<sum;
       int n = nums.size();
       for(int i = n-1;i>0;i--)
       {
           p = p-(n*nums[i])+sum;
           // cout<<p<<" ";
           mx = max(mx,p);
       }
       return mx;
    }
};