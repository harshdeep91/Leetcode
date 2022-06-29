int dp[2][n+1];
dp[0][0]=0,dp[1][0]=0; //base case
dp[0][1]=0,dp[1][1]=1;
//put all 6 type of based on type
for(int i=2;i<=n;i++)
{
// --
// --
dp[0][i]=dp[0][i-2];
dp[1][i]=dp[1][i-2];
// |
dp[0][i]+=dp[0][i-1];
dp[1][i]+=dp[1][i-1];
// _|  if dp[0][i-1]!=0 then only we canplace
if(dp[0][i-1])
dp[0][i]=dp[0][i-2];
dp[1][i]=dp[1][i-2];
// --
// --
dp[0][i]=dp[0][i-2];
dp[1][i]=dp[1][i-2];
// --
// --
dp[0][i]=dp[0][i-2];
dp[1][i]=dp[1][i-2];
// --
// --
dp[0][i]=dp[0][i-2];
dp[1][i]=dp[1][i-2];
}