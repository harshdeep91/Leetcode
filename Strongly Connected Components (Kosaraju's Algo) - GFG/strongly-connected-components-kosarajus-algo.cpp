// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<bool> &vis,stack<int> &s,vector<int> adj[])
	{
	    vis[i]=1;
	    for(auto x:adj[i])
	    {
	        if(!vis[x])
	        dfs(x,vis,s,adj);
	    }
	    s.push(i);
	}
	void dfs2(int i,vector<bool> &inset,vector<bool> &vis,vector<int> adj[])
	{
	    vis[i]=1;
	    for(auto x:adj[i])
	    {
	        if(!vis[x])
	        dfs2(x,inset,vis,adj);
	       // else if(vis[x]&&inset[x])
	    }
	   // s.push(i);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> vis(V,0) ,vis2(V,0);
        vector<int> adj2[V];
        stack<int> s;
        for(int i=0;i<V;i++)
        if(!vis[i])
        dfs(i,vis,s,adj);
        for(int i=0;i<V;i++)
            for(auto x:adj[i])
                adj2[x].push_back(i);
        int count=0;
        while(!s.empty())
        {
            int i=s.top();
            s.pop();
            if(!vis2[i])
            {
                count++;
                dfs2(i,vis,vis2,adj2);
            }
        }
        
        // for(auto x:vis)
        // cout<<x<<" ";
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends