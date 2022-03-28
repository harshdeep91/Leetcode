// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
     void dfs(int i,int &timer,vector<int> adj[],int dis[],int low[],vector<vector<int>> &v,stack<int> &s,int instack[])
    {
        timer++;
        dis[i]=timer;
        low[i]=timer;
        s.push(i);
        instack[i]=1;
        for(auto p:adj[i])
        {
            if(!dis[p])
            {
                dfs(p,timer,adj,dis,low,v,s,instack);
                low[i]=min(low[i],low[p]);                
            }
            else if(instack[p])
            {
                low[i]=min(low[i],low[p]);                
            }
        }
        if(!s.empty()&&low[i]==dis[i])
        {
            vector<int> k;
            while(!s.empty()&&i!=s.top())
            {
                k.push_back(s.top());
                instack[s.top()]=0;
                s.pop();
                
            }
                k.push_back(s.top());
                instack[s.top()]=0;
                s.pop();
                sort(k.begin(),k.end());
                v.push_back(k);
        }
    }
    vector<vector<int>> tarjans(int n, vector<int> adj[])
    {
        vector<vector<int>> v;
        int dis[n]={0},low[n]={0},instack[n]={0},timer=0;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
           if(!dis[i])
           {
               dfs(i,timer,adj,dis,low,v,s,instack);
           }
        }
        sort(v.begin(),v.end());
        return v;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends