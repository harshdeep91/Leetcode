// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution {
public:
bool dfs(int i,int k,vector<vector<int>> adj[],vector<vector<int>> &dp,vector<bool> &vis)
    {
        // cout<<i<<" "<<k<<endl;
         if(k<=0)
            return 1;
        bool mi=false;
        vis[i]=1;
        for(auto x:adj[i])
        {
            if(vis[x[0]])
            continue;
            if(dp[x[0]][k]==-1)
                    dp[x[0]][k]=dfs(x[0],k-x[1],adj,dp,vis);
                mi=mi||dp[x[0]][k];
                if(mi)
                return mi;
        }
        vis[i]=0;
        return mi;
    }
    static bool cmp(vector<int> A,vector<int> B)
    {
        return A[1]>B[1];
    }
    bool pathMoreThanK(int n, int e, int k, int *a) 
    { 
         vector<vector<int>> adj[n],dp(n,vector<int>(k+1,-1));
        vector<bool> vis(n,0);
        for(int i=0;i<3*e;i+=3)
            {
                // cout<<a[i]<<" "<<a[i+1]<<" "<<a[i+2]<<endl;
                adj[a[i]].push_back({a[i+1],a[i+2]});
                adj[a[i+1]].push_back({a[i],a[i+2]});
            }
            for(int i=0;i<n;i++)
            sort(adj[i].begin(),adj[i].end(),cmp);
        bool mi=dfs(0,k,adj,dp,vis);
        return mi;
    } 
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends