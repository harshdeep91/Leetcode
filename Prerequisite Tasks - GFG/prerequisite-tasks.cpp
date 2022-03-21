// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
 bool dfs(int i,vector<int> adj[],vector<bool> &vis,vector<bool> &path)
    {
        
        path[i]=1;
        vis[i]=1;
        // cout<<i<<" "<<path[i]<<" "<<vis[i]<<" "<<endl;
        for(auto x:adj[i])
        {
            if(!vis[x])
            {
                if(dfs(x,adj,vis,path))
                return true;
            }
            else if(vis[x]&&path[x]) 
            return true;
        }
           path[i]=0;
           return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
         vector<bool> vis(V,0),path(V,0);
         for(int i=0;i<V;i++)
         {
             if(!vis[i]&&dfs(i,adj,vis,path))
             return true;
         }
       return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int> adj[N];
	    for(int i=0;i<pre.size();i++)
	    {
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    return !isCyclic(N,adj);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends