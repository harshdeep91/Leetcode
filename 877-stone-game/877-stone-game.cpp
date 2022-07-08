class Solution {
    vector<int> p;
     vector<vector<int>> dp;
public:
    int solve(int i,int j)
    {
        if(i>j)return 0;
          if(dp[i][j]!=-1)return dp[i][j];
                // cout<<i<<" "<<j<<endl;

            // we want single function such that awin= x+y+ awin (not bwin)
        int Awin_i,Awin_j;
            if(p[i+1]+solve(i+2,j)>p[j]+solve(i+1,j-1)) Awin_i=p[i]+solve(i+2,j);
            else    Awin_i=p[i]+solve(i+1,j-1);
        
          if(p[i]+solve(i+1,j-1)>j-1>=i?p[j-1]:0+solve(i,j-2))   Awin_j=p[j]+solve(i+1,j-1);
            else     Awin_j=p[j]+solve(i,j-2);
        
            return  dp[i][j]=max(Awin_i,Awin_j);
    }
    bool stoneGame(vector<int>& piles) {
        //every player will choose maximum
        //for a to win b must loose
        // A will pick such that we got min score
        // 3 8 4 3 2
        p=piles;
        dp.resize(p.size(),vector<int>(p.size(),-1));
        int x=solve(0,p.size()-1),sum=0;
        for(auto y:p)sum+=y;
        sum-=x;
        // cout<<x<<" "<<sum<<endl;
        return x>sum;
    }
};