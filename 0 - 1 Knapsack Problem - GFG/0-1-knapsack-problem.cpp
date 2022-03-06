// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
         int dp[2][W+1];
        bool flag=1;
        for(int i=0;i<=n;i++)
        {
            flag=!flag;
            for(int j=0;j<=W;j++)
            {
                
                if(j==0||i==0)
                dp[flag][j]=0;
                else if(wt[i-1]<=j)
                dp[flag][j]=max(dp[!flag][j-wt[i-1]]+val[i-1],dp[!flag][j]);
                else
                dp[flag][j]=dp[!flag][j];
                // cout<<dp[flag][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[flag][W];
    }
    
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends