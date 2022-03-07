// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N];
        for(int g=1;g<N;g++)
        {
            int i=0,k;
            for(int j=g;j<N;i++,j++)
            {
                 if(g==1)
                 dp[i][j]=0;
                 else if(g==2)
                 dp[i][j]=arr[i]*arr[j-1]*arr[j];
                 else
                 {
                     k=i+1;
                     dp[i][j]=INT_MAX;
                     while(k<j)
                     {
                         dp[i][j]=min(dp[i][j],(dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]));
                         k++;
                     }
                 }
                //  cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[0][N-1];
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends