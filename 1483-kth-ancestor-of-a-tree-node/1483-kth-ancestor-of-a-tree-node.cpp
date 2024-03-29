
class TreeAncestor {
public:
    // vector<int,vector<int>> v;
  vector<vector<int>>dp;
    TreeAncestor(int n, vector<int>& parent) 
    {
        dp=vector<vector<int>>(20,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=parent[i];
        }
        for(int i=1;i<20;i++)
        {
            for(int j=1;j<n;j++)
            {
                int x=dp[i-1][j];
                if(x==-1)
                {
                    dp[i][j]=x;
                }
                else
                {
                    dp[i][j]=dp[i-1][x];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) 
    {
        for(int i=0;i<20;i++)
        {
            if(k&(1<<i))
            {
                node=dp[i][node];
                if(node==-1)
                {
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */