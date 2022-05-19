class Solution {
    vector<vector<int>> dp,mat;
    int m,n,mx;
public:
     bool check(int i,int j,int val)
     {
       if(i>=m||i<0||j>=n||j<0||mat[i][j]<=val)
           return 0;
         return 1;
     }
    int dfs(int i,int j)
    {
        if(dp[i][j])
            return dp[i][j];
        int m=0;
        if(check(i+1,j,mat[i][j]))//right
            m=max(m,dfs(i+1,j));
        if(check(i,j+1,mat[i][j]))//down
            m=max(m,dfs(i,j+1));
        if(check(i-1,j,mat[i][j]))//left
            m=max(m,dfs(i-1,j));
        if(check(i,j-1,mat[i][j]))//up
            m=max(m,dfs(i,j-1));
         mx=max(mx,m+1);
            return dp[i][j]=m+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(),n=matrix[0].size(),dp.resize(m,vector<int>(n,0)),mx=0,mat=matrix;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!dp[i][j])
                    dfs(i,j);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return mx;
    }
};