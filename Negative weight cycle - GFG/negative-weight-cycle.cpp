// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    static bool cmp(vector<int> A,vector<int> B){
        return A[2]<B[2];
    }
    bool neg(int i,int n, vector<vector<int>>edges,vector<int> &cost)
    {
        cost[i]=0;
	    for(int i=1;i<n;i++)
	    {
	        bool updated=0;
	        for(auto x:edges)
	        {
	             int u=x[0];
	             int v=x[1];
	             int pcost=x[2];
	             if(cost[u]!=INT_MAX&&cost[v]>pcost+cost[u])
	             {
	                 cost[v]=pcost+cost[u];
	                 updated=1;
	             }
	        }
	        if(!updated)
	        return false;
	        
	    }
	    
	        for(auto x:edges)
	        {
	             int u=x[0];
	             int v=x[1];
	             int pcost=x[2];
	             if(cost[v]>pcost+cost[u])
	             {
	                 cost[v]=pcost+cost[u];
	                    return true;
	             }
	        }
	        return false;
    }
    
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    sort(edges.begin(),edges.end(),cmp);
	    vector<int> cost(n,INT_MAX);
	   return neg(0,n,edges,cost);
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends