// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int mx=0;
       vector<int> dp(n,1);
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               if(a[j]>a[i]&&dp[j]<dp[i]+1)
               dp[j]=dp[i]+1;
               mx=max(mx,dp[j]);
           }
       }
       return mx;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends