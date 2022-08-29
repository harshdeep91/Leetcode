class Solution {
public:
    bool check(int x,int y,vector<vector<char>>& grid)
    {
        if(x<grid.size()&&y<grid[0].size()&&x>=0&&y>=0&&grid[x][y]=='1')
        return true;
        return false;
    }
    void dfs(int x,int y,vector<vector<char>>& grid)
    {
        grid[x][y]='0';
        if(check(x,y+1,grid))dfs(x,y+1,grid);
        if(check(x,y-1,grid))dfs(x,y-1,grid);
        if(check(x+1,y,grid))dfs(x+1,y,grid);
        if(check(x-1,y,grid))dfs(x-1,y,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};