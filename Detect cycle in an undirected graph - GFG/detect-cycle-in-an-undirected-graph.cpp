// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
      bool dfs(int i,int parent,vector<int> adj[],vector<bool> &vis,vector<bool> &path)
    {
        
        path[i]=1;
        vis[i]=1;
        // cout<<i<<" "<<path[i]<<" "<<vis[i]<<" "<<endl;
        for(auto x:adj[i])
        {
            if(!vis[x])
            {
                if(dfs(x,i,adj,vis,path))
                return true;
            }
            else if(path[x]&&x!=parent) 
            return true;
        }
           path[i]=0;
           return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,0),path(V,0);
        
         for(int i=0;i<V;i++)
         {
             if(!vis[i]&&dfs(i,-1,adj,vis,path))
             return true;
         }
       return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends