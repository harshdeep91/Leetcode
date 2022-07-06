class Solution {
    vector<int> vis,m,qt;
public:
    int dfs(int i,vector<int> adj[])
    {
        // cout<<i<<" ";
        vis[i]=1;
        int mi=qt[i];
        for(auto x:adj[i])
        {
            if(!vis[x])
            {
                mi=min(mi,dfs(x,adj));
            }
            else
            {
                mi=min(mi,qt[x]);
            }
        }
        
        return qt[i]=mi;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& q) {
        int n=q.size();
        vis.resize(n,0),m.resize(n,0);
        vector<int> adj[n];
        for(int i=0;i<q.size();i++)
            m[q[i]]=i;
        for(auto x:richer)
            adj[x[1]].push_back(x[0]);
        //now update quiet values by dfs
        qt=q;
        for(int i=0;i<q.size();i++)
            if(!vis[i])dfs(i,adj);
        for(int i=0;i<q.size();i++)
            qt[i]=m[qt[i]];
        return qt;
    }
};