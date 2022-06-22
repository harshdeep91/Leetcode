class Solution {
    vector<vector<vector<double>>> dp;
    int m;
    vector<int> dx={-2,-1,1,2};
public:
    double solve(int i,int j,int k)
    {
        //travel all 8 position
        // cout<<i<<" "<<j<<" "<<k<<endl;
         if(i>=m||i<0||j>=m||j<0||k<0)return 0;
        if(k==0)return 1;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        double path=0;
        //r+c => -3 to -1
        for(auto r:dx)
        {
            if(abs(r)==2)
                path+=(solve(i+r,j-1,k-1)+solve(i+r,j+1,k-1));
            else
                path+=(solve(i+r,j-2,k-1)+solve(i+r,j+2,k-1));
        }
        return dp[i][j][k]=path/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        //find probabily at every steps
        //count paths and after returning divide it by k*8
        dp.resize(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        m=n;
        return solve(row,column,k);
        // cout<<x<<" ";
        // return (double)x/pow(8,k);
        // return x;
    }
};