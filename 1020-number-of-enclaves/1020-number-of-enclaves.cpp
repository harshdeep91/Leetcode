class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(min(i,j)>=0&&i<grid.size()&&j<grid[0].size()&&grid[i][j]==1)
        {
            // cout<<i<<" "<<j<<endl;
            grid[i][j]=2;
            dfs(i+1,j,grid);
            dfs(i,j+1,grid);
            dfs(i-1,j,grid);
            dfs(i,j-1,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //we need to travel two times
        //first from left and up
        //second from right and down
        //or 
        //we can individually go through all boundaries and if 
        //we got 1 mark 2 else 0
        for(int i=0;i<grid[0].size();i++)
        {
            if(grid[0][i]) dfs(0,i,grid);
            if(grid[grid.size()-1][i]) dfs(grid.size()-1,i,grid);
        }
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0]==1) dfs(i,0,grid);
            if(grid[i][grid[0].size()-1]==1) dfs(i,grid[0].size()-1,grid);
        }
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
                count+=grid[i][j]==1;
                // cout<<grid[i][j]<<" ",count+= grid[i][j]==1;
            cout<<endl;
        }
        return count;
    }
};

// [[0,0,0,1,1,1,0,1,0,0],[1,1,0,0,0,1,0,1,1,1],[0,0,0,1,1,1,0,1,0,0],[0,1,1,0,0,0,1,0,1,0],[0,1,1,1,1,1,0,0,1,0],[0,0,1,0,1,1,1,1,0,1],[0,1,1,0,0,0,1,1,1,1],[0,0,1,0,0,1,0,1,0,1],[1,0,1,0,1,1,0,0,0,0]]