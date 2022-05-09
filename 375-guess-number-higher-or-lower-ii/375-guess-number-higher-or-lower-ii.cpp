
class Solution {
public:
   
    int getMoneyAmount(int n) {
        int dp[n+1][n+1];
        if(n==1)
            return 0;
        for(int g=1;g<=n;g++)
        {
            // cout<<g<<endl;
            for(int i=1,j=g;j<=n;j++,i++)
            {
                // cout<<i<<" "<<j<<endl;
                if(g==1||g==2)
                    dp[i][j]=i;
                else if(g==3)
                    dp[i][j]=i+1;
                else
                {
                    dp[i][j]=INT_MAX;
                    for(int k=i+1;k<j-1;k++)
                        dp[i][j]=min(dp[i][j],max(dp[i][k-1],dp[k+1][j])+k);
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[1][n];
    }
};