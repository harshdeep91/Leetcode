class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[s.size()][s.size()];
        for(int g=0;g<s.size();g++)
        {
            for(int i=0,j=g;j<s.size();j++,i++)
            {
                
                if(g==0)
                    dp[i][j]=1;
                else if(g==1)
                    dp[i][j]=s[i]==s[j]?2:1;
                else if(s[i]==s[j])
                    dp[i][j]=2+dp[i+1][j-1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[0][s.size()-1];
    }
};