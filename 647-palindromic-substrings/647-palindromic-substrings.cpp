class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),count=0;
        bool dp[n][n];
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;j++,i++)
            {
                if(g==0)
                    dp[i][j]=1;
                else if(g==1)
                    dp[i][j]=s[i]==s[j];
                else
                    dp[i][j]=s[i]==s[j]&&dp[i+1][j-1];
                count+=dp[i][j];
            }
        }
        return count;
        
    }
};