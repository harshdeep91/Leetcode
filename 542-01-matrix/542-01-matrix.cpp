class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int dis=0,size,r,c,m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                q.push({i,j});
                else
                    mat[i][j]=INT_MAX;
            }
        
        while(!q.empty())
        {
             size=q.size();
            dis++;
            while(size--)
            {
                 r=q.front().first;
                 c=q.front().second;
                 q.pop();
                 
                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                         if((i==0||j==0)&&r+i>=0&&c+j>=0&&r+i<m&&c+j<n&&mat[r+i][c+j]>dis)
                            {
                                mat[r+i][c+j]=dis;
                                q.push({r+i,c+j});
                            }
                    }
                }
               
            }
            //  for(int i=0;i<m;i++)
            //  {
            //      for(int j=0;j<n;j++)
            //          cout<<mat[i][j]<<" ";
            //      cout<<endl;
            //  }
            // cout<<endl;
        }
        return mat;
    }
};