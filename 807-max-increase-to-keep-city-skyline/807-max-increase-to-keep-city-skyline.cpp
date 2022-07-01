class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        //after finding pattern we see we are not disturbing the max height only less height then max
        vector<int> row,col;
        for(int i=0;i<grid.size();i++)
        {
            int rmx=0,cmx=0;
            for(int j=0;j<grid[i].size();j++)
            {
                rmx=max(rmx,grid[i][j]);
                cmx=max(cmx,grid[j][i]);
            }
            row.push_back(rmx);
            col.push_back(cmx);
        }
        int ans=0,count;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
            {
                count= min(row[i],col[j])-grid[i][j];
                count=count<0?0:count;
                ans+= count;
            }
        return ans;
    }
}; 