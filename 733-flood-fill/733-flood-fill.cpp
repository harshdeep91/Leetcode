class Solution {
public:
    int oldcolor,newcolor;
    void solve(int i,int j, vector<vector<int>> &mat)
    {
        // cout<<i<<" "<<j<<endl;
        if(i>=0&&i<mat.size()&&j>=0&&j<mat[0].size()&&mat[i][j]==oldcolor)
        {
           mat[i][j]=newcolor;
           solve(i-1,j,mat);
           solve(i+1,j,mat);
           solve(i,j-1,mat);
           solve(i,j+1,mat);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int newColor) {
         oldcolor=mat[sr][sc];
         newcolor=newColor;
        
        // cout<<oldcolor<<newcolor<<endl;
        if(oldcolor!=newcolor)
        solve(sr,sc,mat);
        return mat;
    }
};