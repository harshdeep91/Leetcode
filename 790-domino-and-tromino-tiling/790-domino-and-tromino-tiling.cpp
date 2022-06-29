class Solution {
    int size,m=pow(10,9)+7;
    vector<vector<int>> dp;
public:
    int solve(int i,int j,string s)
    {
        // cout<<i<<" "<<j<<" "<<count<<endl;
        if(i==size&&j==size)
            return 1;
        if(i>size||j>size)return 0;
        if(dp[i][j]!=-1)return dp[i][j]%m;
        long long x=0;
             if(i==j)
             {
                 x+=solve(i+2,j+2,s+"12")%m;//--
                 x+=solve(i+1,j+1,s+"3")%m;// |
                 x+= solve(i+1,j+2,s+"5")%m; // |_
                 x+= solve(i+2,j+1,s+"7")%m;//|^
             }
             else if(abs(i-j)==1)
             {
                 if(i-j==1)
                 x+= solve(i+1,j+2,s+"4")%m;// _| 
                 else
                     x+= solve(i+2,j+1,s+"6")%m;// ^| 
                 x+= solve(i+2,j,s+"1")%m+solve(i,j+2,s+"2")%m;
             }
        return dp[i][j]=x%m;
    }
    int numTilings(int n) {
        size=n;
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,0,"");
            
    }
};