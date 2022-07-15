class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //fill the last elements
        int  mi=INT_MAX;
        for(int i=matrix.size()-2;i>=0;i--)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                matrix[i][j]+= min(j-1>=0?matrix[i+1][j-1]:INT_MAX,min(j+1<matrix.size()?matrix[i+1][j+1]:INT_MAX,matrix[i+1][j]));
            }
        }
           for(int j=0;j<matrix[0].size();j++)mi=min(mi,matrix[0][j]);
        return mi;
    }
};