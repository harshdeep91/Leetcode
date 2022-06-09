class Solution {
public:
    int minDistance(string word1, string word2) {
        //common subsequenc
        //ae ea
        //make all subsqueqnce store it and check one by one which is greater in len
        
        // dp
        int m=word1.size(),n=word2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(word1[i-1]!=word2[j-1])
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                }
                else
                    dp[i][j]=dp[i-1][j-1]; 
                // cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m][n];
    }
};