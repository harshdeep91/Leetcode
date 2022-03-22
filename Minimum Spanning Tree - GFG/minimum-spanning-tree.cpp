// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> cost(V,INT_MAX),vis(V,0);
        q.push({0,0}); 
        cost[0]=0;
        while(!q.empty())
        {
            int i=q.top().second;
            int pcost=q.top().first;
            q.pop();
                for(auto x:adj[i])
                {
                    if(!vis[x[0]]&&cost[x[0]]>x[1])
                    {
                        cost[x[0]]=x[1];
                        q.push({cost[x[0]],x[0]});
                    }
                }
            vis[i]=1;
        }
        int sum=0;
        for(int i=0;i<V;i++)
                    sum+=cost[i];
        return sum;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends