class Solution {
public:
    int dfs(int i,int k,int &dst,vector<vector<int>> adj[],vector<vector<int>> &dp)
    {
        // cout<<i<<" "<<count<<endl;
        if(i==dst)
            return 0;
        if(k<0)
            return INT_MAX;
        int mi=INT_MAX;
        for(auto x:adj[i])
        {
            if(dp[x[0]][k]==-1)
                dp[x[0]][k]=dfs(x[0],k-1,dst,adj,dp);
            if(dp[x[0]][k]!=INT_MAX)
                mi=min(dp[x[0]][k]+x[1],mi);
        }
        return mi;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<int>> adj[n],dp(n,vector<int>(n,-1));
        vector<bool> vis(n,0);
        for(int i=0;i<flights.size();i++)
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        int mi=dfs(src,k,dst,adj,dp);
        return mi==INT_MAX?-1:mi;
    }
};