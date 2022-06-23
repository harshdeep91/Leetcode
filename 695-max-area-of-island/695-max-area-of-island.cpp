class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!=1)
            return 0;
        int count=1;
        grid[i][j]=0;
        
        count+=solve(i+1,j,grid);
        count+=solve(i-1,j,grid);
        count+=solve(i,j+1,grid);
        count+=solve(i,j-1,grid);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                
                if(grid[i][j]==1)
                {
                    int t=solve(i,j,grid);
                    mx=max(mx,t);
                    // cout<<i<<" "<<j<<" "<<t<<endl;
                }
            }
        }
        return mx;
    }
};