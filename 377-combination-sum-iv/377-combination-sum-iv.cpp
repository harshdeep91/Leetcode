class Solution {
int count;
    vector<int> num,dp;
public:
    int solve(int sum)
    {
        if(sum==0)
                return dp[sum]=1;
        else if(sum>0)
            {
                if(dp[sum]!=-1)
                    return dp[sum];
                int ans = 0;
                for (int i = 0; i < num.size();i++)
                   ans+=solve(sum - num[i]);
                return dp[sum] = ans;
            }
            return 0;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.clear(); dp.resize(target+1, -1);
        num = nums;
        solve(target);
        return dp[target];
    }
};