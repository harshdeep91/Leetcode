class Solution {
    int n;
public:
   void dfs(int i,int j,vector<vector<int>> &v)
   {
       if(min(i,j)>=0&&max(i,j)<n*3&&v[i][j]==1)
       {
           v[i][j]=0;
           dfs(i+1,j,v);
           dfs(i,j+1,v);
           dfs(i-1,j,v);
           dfs(i,j-1,v);
       }
   }
    int regionsBySlashes(vector<string>& grid) {
        n=grid.size();
        vector<vector<int>> v(n*3,vector<int>(n*3,1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                    v[i*3+2][j*3]=v[i*3+1][j*3+1]=v[i*3][j*3+2]=0;
                else if(grid[i][j]=='\\')
                   v[i*3][j*3]=v[i*3+1][j*3+1]=v[i*3+2][j*3+2]=0;
            }
        }
        
        // for(auto x:v)
        // {
        //     for(auto y:x)
        //         cout<<y<<" ";
        //   cout<<endl;
        // }
        int count=0;
        for(int i=0;i<n*3;i++)
            for(int j=0;j<n*3;j++)
                if(v[i][j]==1)count++,dfs(i,j,v);
        return count;
    }
};