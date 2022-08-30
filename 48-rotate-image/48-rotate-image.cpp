class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     //swap diagonally and then swap vertically 
        int n=matrix.size();
        for(int g=1;g<n;g++)
        {
            for(int i=0,j=g;i<n&&j<n;i++,j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //swap vertically
        for(int g=0;g<n/2;g++)
        {
            for(int i=0,j=g;i<n&&j<n;i++)
            {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
        
    }
};