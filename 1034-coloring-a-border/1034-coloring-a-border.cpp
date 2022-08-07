class Solution {
    vector<vector<int>> tmp,mat;
    vector<vector<bool>> vis;
    int color,m,n,old;
public:
    bool check(int i,int j)
    {
        if(min(i,j)>=0&&i<m&&j<n&&mat[i][j]==old)
            return 1;
        return 0;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int colo) {
        tmp=grid,mat=grid,color=colo,m=grid.size(),n=grid[0].size(),old=grid[row][col];
        vis.resize(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                vis[r][c]=1;
                int boundary=0;
                // for(auto x:tmp)
                // {
                //     for(auto y:x)cout<<y<<" ";
                //     cout<<endl;
                // }
                if(check(r+1,c))
                {
                    boundary++;
                    if(!vis[r+1][c])q.push({r+1,c});
                }
                if(check(r,c-1))
                {
                    boundary++;
                    if(!vis[r][c-1])q.push({r,c-1});
                }
                if(check(r-1,c))
                {
                    boundary++;
                    if(!vis[r-1][c])q.push({r-1,c});
                }
                if(check(r,c+1))
                {
                    boundary++;
                    if(!vis[r][c+1])q.push({r,c+1});
                }
                if(boundary!=4)//means all four are not adjacent to same color
                    tmp[r][c]=color;
            }
        }
        return tmp;
    }
};