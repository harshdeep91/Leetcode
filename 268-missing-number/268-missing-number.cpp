class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),i=0;
        long long sum=(double)(n/2.0)*(n+1);
        while(i<n)
            sum-=nums[i++];
        return sum;
    }
};