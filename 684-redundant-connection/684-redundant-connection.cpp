class Solution {
    vector<int> ans,vis;
    int index,time=1;
public:
    void dfs(int i,int parent,vector<pair<int,int>> adj[])
    {
        vis[i]=time++;
        
        for(auto x:adj[i])
        {
            
            if(!vis[x.first])
            {
               dfs(x.first,i,adj);
                if(vis[x.first]<=vis[i])
                {
                    index=max(index,x.second);
                    vis[i]=vis[x.first];
                    // cout<<i<<"--> "<<x.first<<" "<<index<<" "<<x.second<<endl;
                    return;
                }
            }
            else if(x.first!=parent)
            {
                index=x.second;
                vis[i]=vis[x.first];
                // cout<<i<<"--> "<<x.first<<" "<<index<<" "<<x.second<<endl;
                return ;
            }
            
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        index=-1;
        vector<pair<int,int>> adj[edges.size()+1];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],i});
            adj[edges[i][1]].push_back({edges[i][0],i});
        }
        vis.resize(edges.size()+1,0);
          dfs(1,0,adj);
        // cout<<index<<" ";
        return edges[index];
    }
};