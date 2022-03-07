// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        // cout<<sum<<endl;
        if(sum&1||N<2)
        return false;
        sum/=2;
        bool dp[N+1][sum+1];
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
               
                if(i==0)
                dp[i][j]=0;
                else if(j==0)
                dp[i][j]=1;
                else 
                dp[i][j]=dp[i-1][j]||(arr[i-1]<=j&&dp[i-1][j-arr[i-1]]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[N][sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends