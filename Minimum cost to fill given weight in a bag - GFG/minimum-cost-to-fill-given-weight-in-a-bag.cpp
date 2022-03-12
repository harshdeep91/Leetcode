// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int solve(int cost[], int N, int W) 
	{
	   if(N==0)
	   {
	       if(W==0)
	       return 0;
	       return INT_MAX;
	   }
	   int x=INT_MAX,y=INT_MAX;
	   if(cost[N-1]>=0&&N<=W)
	      x=solve(cost,N,W-N);
	      if(x!=INT_MAX)
	        x+=cost[N-1];
	     y=solve(cost,N-1,W);
	    return min(x,y); 
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
	   // cout<<N<<" "<<W<<endl;
	   int dp[N+1][W+1];
	   for(int i=0;i<=N;i++)
	   {
	       for(int j=0;j<=W;j++)
	       {
	           if(j==0)
	           dp[i][j]=0;
	          else if(i==0)
	          dp[i][j]=INT_MAX;
	          else if(cost[i-1]!=-1&&i<=j&&dp[i][j-i]!=INT_MAX)
	          dp[i][j]=min(dp[i][j-i]+cost[i-1],dp[i-1][j]);
	          else
	          dp[i][j]=dp[i-1][j];
	       //   cout<<dp[i][j]<<" ";
	       }
	       //cout<<endl;
	   }
	   return dp[N][W]==INT_MAX?-1:dp[N][W];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends