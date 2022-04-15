class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
        for(int i=1;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++)
                mat[i][j]+=mat[i-1][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
            for(int j=col1;j<=col2;j++)
            {
                // cout<<mat[row2][j]<<" "<<mat[row1-1][j]<<endl;
                sum+=mat[row2][j];
                if(row1>0)
                sum-=mat[row1-1][j];
                    
            }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */