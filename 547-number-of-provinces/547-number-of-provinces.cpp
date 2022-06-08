class Solution {
public:
     void dfs(int i,vector<vector<int>>& mat)
     {
         for(int j=0;j<mat[i].size();j++)
         {
             if(mat[i][j])
             {
                  mat[i][j]=0;
                  mat[j][i]=0;
                  dfs(j,mat);
             }
         }
     }
    int findCircleNum(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][i])
            {
                count++;
                dfs(i,mat);
            }
        }
        return count;
    }
};