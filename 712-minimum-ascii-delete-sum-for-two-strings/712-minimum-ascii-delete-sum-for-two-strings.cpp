class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //find common subsequence
        //then remove extra charac
        int m=s1.size(),n=s2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0&&j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=s2[j-1]+dp[i][j-1];
                else if(j==0)
                    dp[i][j]=s1[i-1]+dp[i-1][j];
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else //min because it indicates that we have long subsequence
                    dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[m][n];
    }
};