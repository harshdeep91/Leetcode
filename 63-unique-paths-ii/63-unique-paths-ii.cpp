class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int sum=obstacleGrid[0].size();
        int dp[n][sum];
        bool flag=1,flag2=1;
        for(int i=0;i<n;i++)
{   for(int j=0;j<sum;j++)
   {
    if(i==0&&obstacleGrid[i][j]==1)
       flag=0;
    if(j==0&&obstacleGrid[i][j]==1)
       flag2=0;
    if((i==0&&flag==1)||(j==0&&flag2==1))
    dp[i][j]=1;
    else
        dp[i][j]=0;
      }
}
        for(int i=1;i<n;i++)
{
    for(int j=1;j<sum;j++)
   {
        if(obstacleGrid[i][j]==1)
        dp[i][j]=0;
        else
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
   }
}  
return dp[n-1][sum-1]; 
    }
};