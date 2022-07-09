class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        //every time our len increase
        //in first we have 1 row and 1 col then 2 row 2col so on
        //max distance could be max(rows,cols);
        //means time complexity is max of(rows,cols)^2;
        //dir=> 
        //right =>  i             ,j to j+dis //dis=1 , 0
        //down  =>  i+1 to i+dis  ,j+dis
        //left  =>  i+dis           ,j+dis-1 to j-dis
        //up    =>  i+dis-1 to i-dis,j-dis
        //new point => ,j++
        int i=rStart,j=cStart,dis=1,k=0;
        vector<vector<int>> ans;
        while(ans.size()<rows*cols)
        {
            // cout<<i<<" "<<j<<endl;
            //travel right
            k=dis;
            //1,4
            while(k--)
            {
                if(i>=0&&i<rows&&j>=0&&j<cols)
                    ans.push_back({i,j});
                j++;
            }
            // cout<<i<<" "<<j<<endl;
            //1,5 but this value is not pushed
            k=dis;
            while(k--)//down
            {
                if(i>=0&&i<rows&&j>=0&&j<cols)
                    ans.push_back({i,j});
                i++;
            }
            //2,5
            // cout<<i<<" "<<j<<endl;
            dis++;
            k=dis;
            while(k--)//left
            {
                if(i>=0&&i<rows&&j>=0&&j<cols)
                    ans.push_back({i,j});
                j--;
            }
            //2,3
            // cout<<i<<" "<<j<<endl;
            k=dis;
            while(k--)//up
            {
                if(i>=0&&i<rows&&j>=0&&j<cols)
                    ans.push_back({i,j});
                i--;
            }
            dis++;
        }
       return ans;
    }
};