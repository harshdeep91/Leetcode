class Solution {
public:
    bool isInterleave(string s1, string s2,string s3){
        int m=s1.size(),n=s2.size();
                      if(s3.size()!=m+n)
                      return false;
        bool dp[m+1][n+1],one,two;
        for(int i=0;i<=m;i++)
                      {
                          for(int j=0;j<=n;j++)
                          {
                              if(i==0&&j==0)
                                  dp[0][0]=1;
                              else if(i==0)
                                  dp[i][j]=(s2[j-1]==s3[j-1]&&dp[i][j-1])?1:0;
                              else if(j==0)
                                 dp[i][j]=(s1[i-1]==s3[i-1]&&dp[i-1][j])?1:0;
                              else
                              {
                                  one=(s2[j-1]==s3[j+i-1]&&dp[i][j-1])?1:0;
                                  two=(s1[i-1]==s3[i+j-1]&&dp[i-1][j])?1:0;
                                  dp[i][j]=one||two;
                              }
                          }
                      }
                      return dp[m][n];
    }
};