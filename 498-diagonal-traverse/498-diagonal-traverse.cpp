class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //diagonal up starting at j=0 going till i>=0 && j<n
        //2,0 -> 1,1 -> 1-1,1+1,=> i--,j++
        //diagonal down => 0,1-> 1,0 -> i++,j--
        //diagonal up to down -> -1,1 -> i++
        //diagonal down to up-> 2,-1 -> j++
        vector<int> v;
        int i=0,j=0,m=mat.size(),n=mat[0].size();
        while(v.size()<m*n)
        {
            //diagonal up
            while(i>=0&&j<n)
                v.push_back(mat[i--][j++]);
            //diagonal up to down
            i++;
            if(j==n)//crossed
                i++,j--;
            //diagonal down
            while(i<m&&j>=0)
                v.push_back(mat[i++][j--]);
            j++;
            if(i==m)//crossed
                i--,j++;
        }
        return v;
    }
};