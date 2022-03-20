class Solution {
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis)
    {
        vis[i]=1;
        for(auto x:adj[i])
        {
            if(!vis[x])
                dfs(x,adj,vis);
       }
    }
    int makeConnected(int n, vector<vector<int>>& edge) {
        vector<int> adj[n],vis(n,0);
        for(int i=0;i<edge.size();i++)
        {
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,adj,vis);
            }
        }
        int extra=edge.size()-(n-1);
        
        return extra>=0?count-1:-1;
    }
};