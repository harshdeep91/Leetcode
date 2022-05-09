
class Solution {
    vector<vector<int>> dp;
public:
    int solve(int s,int e)
    {
        if(s>=e)
            return 0;
        if(dp[s][e])
            return dp[s][e];
        int ans=INT_MAX,val;
        for(int i=s;i<=e;i++)
        {
            val=max(solve(s,i-1),solve(i+1,e))+i;
            ans=min(ans,val);
        }
        return dp[s][e]=ans;
    }
    int getMoneyAmount(int n) {
        dp.clear();
        dp.resize(n+1,vector<int>(n+1,0));
        return solve(1,n);
    }
};