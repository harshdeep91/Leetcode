// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	  queue<int> q;
	  vector<int> colors(V,-1);
	  for(int i=0;i<V;i++)
	  {
	      if(colors[i]==-1)
	      {
	          q.push(i);
	          bool color=1;
	          colors[i]=0;
        	           while(!q.empty())
        	  {
        	      int size=q.size();
        	      while(size--)
        	      {
        	          int i=q.front();
        	          q.pop();
        	          for(auto x:adj[i])
        	          {
        	           //   cout<<x<<" "<<color<<endl;
        	              if(colors[x]==-1)
        	               {
        	                   colors[x]=color;
        	                   q.push(x);
        	               }
        	               else if(colors[x]!=color)
        	               return false;
        	          }
        	      }
        	      color=!color;
        	  }
	      }
	  }
	 
	  return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends