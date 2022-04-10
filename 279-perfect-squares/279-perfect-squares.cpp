class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i*i<=n;i++)
        {
            v.push_back(i*i);
        }
        int m=v.size();
        int dp[n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                    dp[j]=0;
                else if(i==0)
                    dp[j]=INT_MAX;
                else if(v[i-1]<=j)
                    dp[j]=min(dp[j],1+dp[j-v[i-1]]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n];
    }
};