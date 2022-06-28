struct node{
    int l=0,u=0,r=0,d=0,x=0;
};
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mine) {
        vector<vector<bool>> mines(n,vector<bool>(n,1)); 
        vector<vector<node>> dp(n,vector<node> (n));
        //traveling in topleft to bottomright 
        for(auto x:mine)
            mines[x[0]][x[1]]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mines[i][j])
                {
                    if(i==0&&j==0)
                    {
                        dp[i][j].l=1,dp[i][j].u=1;
                    }
                    else if(i==0)//means up=0;
                    {
                        dp[i][j].l=dp[i][j-1].l+1,dp[i][j].u=1;
                    }
                    else if(j==0)
                    {
                        dp[i][j].l=1,dp[i][j].u=dp[i-1][j].u+1;
                    }
                    else
                    {
                        dp[i][j].l=dp[i][j-1].l+1,dp[i][j].u=dp[i-1][j].u+1;
                    }
                }
            }
        }
        int mx=0;
        //traveling in bottomright to topleft
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(mines[i][j])
                {
                    if(i==n-1&&j==n-1)
                    {
                        dp[i][j].r=1,dp[i][j].d=1;
                    }
                    else if(i==n-1)//means up=0;
                    {
                        dp[i][j].r=dp[i][j+1].r+1,dp[i][j].d=1;
                    }
                    else if(j==n-1)
                    {
                        dp[i][j].r=1,dp[i][j].d=dp[i+1][j].d+1;
                    }
                    else
                    {
                        dp[i][j].r=dp[i][j+1].r+1,dp[i][j].d=dp[i+1][j].d+1;
                    }
                }
                dp[i][j].x=min(dp[i][j].l,min(dp[i][j].r,min(dp[i][j].d,dp[i][j].u)));
                mx=max(dp[i][j].x,mx);
            }
        }
        return mx;
    }
};