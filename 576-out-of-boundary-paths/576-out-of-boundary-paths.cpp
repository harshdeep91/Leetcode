class Solution {
    int count,r,c,mod=pow(10,9)+7;
    vector<vector<vector<int>>> vis;
public:
    int solve(int i,int j,int move)
    {
        // cout<<i<<" "<<j<<" "<<move<<" "<<endl;
        if(i<0||i>=r||j<0||j>=c)//means we got out
        {
                return 1;
            // cout<<"yes\n";
        }
        if(move==0) return 0;
        
        if(vis[i][j][move]==-1)
        {
            vis[i][j][move]=solve(i,j+1,move-1);
            vis[i][j][move]=(vis[i][j][move]+solve(i+1,j,move-1))%mod;
            vis[i][j][move]=(vis[i][j][move]+solve(i,j-1,move-1))%mod;
            vis[i][j][move]=(vis[i][j][move]+solve(i-1,j,move-1))%mod;
        }
        return vis[i][j][move];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r=m,c=n,count=0,vis.resize(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove);
    }
};