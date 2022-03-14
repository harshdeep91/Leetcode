class Solution {
public:
    string longestPalindrome(string s) {
        int st=0,e=0;
        bool dp[s.size()][s.size()];
        for(int g=0;g<s.size();g++)
        {
            for(int i=0,j=g;j<s.size();i++,j++)
            {
                if(g==0)
                    dp[i][j]=1;
                else if(g==1)
                    dp[i][j]=s[i]==s[j];
                else
                    dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1])?1:0;
                if(dp[i][j]&&j-i>e-st)
                {
                    e=j;
                    st=i;
                }
            }
        }
        
        return s.substr(st,e-st+1);
    }
};