class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        //travel diagonally and sort them
        int m=mat.size(),n=mat[0].size();
        for(int g=0;g<n;g++)
        {
            vector<int> arr;
            for(int i=0,j=g;i<m&&j<n;i++,j++)
            {
                // cout<<mat[i][j]<<" ";
                arr.push_back(mat[i][j]);
            }
            sort(arr.begin(),arr.end());
            for(int i=0,j=g,k=0;i<m&&j<n;i++,j++,k++)
            {
                mat[i][j]=arr[k];
            }
            // cout<<endl;
        }
        for(int g=1;g<m;g++)
        {
            vector<int> arr;
            for(int j=0,i=g;i<m&&j<n;i++,j++)
            {
                // cout<<mat[i][j]<<" ";
                arr.push_back(mat[i][j]);
            }
            sort(arr.begin(),arr.end());
            for(int i=g,j=0,k=0;i<m&&j<n;i++,j++,k++)
            {
                mat[i][j]=arr[k];
            }
            // cout<<endl;
        }
        return mat;
    }
};