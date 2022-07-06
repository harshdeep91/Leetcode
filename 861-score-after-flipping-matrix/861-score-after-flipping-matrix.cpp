class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        //for getting max value
        //simply make first col 1 by toggling row
        //start traveling col and try to toggle if 0>1
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0]==0)//toggle this row
            {
                for(int j=0;j<grid[0].size();j++)
                    grid[i][j]=!grid[i][j];
            }
        }
        //now toggle every col 
        
        for(int j=0;j<grid[0].size();j++)
        {
            int count1=0,count0=0;
            for(int i=0;i<grid.size();i++)
            {
                if(grid[i][j]==1)count1++;
                else count0++;
            }
            if(count0>count1)//toggle col
            {
                for(int i=0;i<grid.size();i++)
                {
                    grid[i][j]=!grid[i][j];
                }
            }
        }
        //now find the ans
        int ans=0,val,one;
        for(int i=0;i<grid.size();i++)
        {
            val=0,one=1;
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                val+=grid[i][j]*one;
                one*=2;
            }
                ans+=val;
        }
        return ans;
    }
    // [1,0,1,0]
    // [0,0,1,0]
    // [1,0,1,0]
};