// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[4][n+1],len[3]={x,y,z},mod=pow(10,9)+7;
        sort(len,len+3);
        for(int i=0;i<=3;i++)
        {
            // cout<<len[i-1]<<endl;
            for(int j=0;j<=n;j++)
            {
                if(j==0||i==0)
                dp[i][j]=0;
                else
                {
                      dp[i][j]=dp[i-1][j];
                    if(len[i-1]<=j)
                    {
                       if(j==len[i-1]||dp[i][j-len[i-1]])
                       {
                           dp[i][j]=max(dp[i][j-len[i-1]]+1,dp[i-1][j])%mod;   
                       }
                       else
                        dp[i][j]=max(dp[i][j-len[i-1]],dp[i-1][j])%mod;   
                    }
                    
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return dp[3][n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends