class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        dp[0]=1;
        if(s[0]=='0') return 0;
            for(int i=1;i<n;i++)
            {
                if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<'7'))
                {
                    dp[i]=i==1?1:dp[i-2];
                }
                if(s[i]!='0')
                    dp[i]+=dp[i-1];
                // cout<<dp[i]<<" ";
            }
        return dp[n-1];
    }
};