// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
int solve(int j,int count,unordered_map<string,int> &dp,vector<vector<int>>&cost,vector<int>&vis)
{
    
    
    if(count==cost.size())//we selected everything
        return cost[j][0];
    vis[j]=1;
    int low=INT_MAX;
    for(int i=0;i<cost.size();i++)
    {
        
        if(!vis[i]&&cost[j][i])
            low=min(low,solve(i,count+1,dp,cost,vis)+cost[j][i]);
    }
    vis[j]=0;
    return low;
}
int total_cost(vector<vector<int>>cost){
    int n=cost.size();
   unordered_map<string,int> dp;
    vector<int>vis(n,0);
    return solve(0,1,dp,cost,vis);
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends